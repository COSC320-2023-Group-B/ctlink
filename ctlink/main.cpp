#include <iostream>
#include <sstream>
#include <vector>
#include <ctlib/caretaker_static.h>

#include "callback.h"
#include "csv_creator.h"


libct_context_t *get_init_context() {
	libct_context_t* context = NULL;

	libct_init_data_t init_data;
	memset(&init_data, 0, sizeof(init_data));
	init_data.device_class = LIBCT_DEVICE_CLASS_BLE_CARETAKER4;

	libct_app_callbacks_t callbacks = { 0 };
	callbacks.on_device_discovered = on_device_discovered;
	callbacks.on_device_connected_ready = on_device_connected_ready;
	callbacks.on_device_disconnected = on_device_disconnected;
	callbacks.on_data_received = on_data_received;
	callbacks.on_start_measuring = on_start_measuring;

	// libct_init requires a pointer to an empty context, initialisation data, and callback functions
	// callback functions must implement the following functions at least, and the non-implemented must be NULL:
	// on_device_discovered(context, device);
	// on_device_connected_ready(context, device);
	// on_device_disconnected(context, device);
	// on_data_received(context, device, data);
	int status = libct_init(&context, &init_data, &callbacks);
	if (LIBCT_FAILED(status)) {
		// Handle error

		// can you handle this error? just crash
		throw std::runtime_error( "Failed to initialise caretaker context" );
	}

	std::cout << "Successfully initialised caretaker context!" << std::endl << std::endl;

	return context;
}

void discover_devices(libct_context_t* context) {
	const int SEARCH_TIME = 20000;

	int status = libct_start_discovery(context, SEARCH_TIME);

	if (LIBCT_FAILED(status)) {
		// did not discover devices
		throw std::runtime_error("Could not discover devices");
	}
}


bool is_int(const std::string& x) {
	std::istringstream iss(x);
	int num;
	iss >> num;
	return iss.eof() && !iss.fail();
}


// user interface to select device to pair with
libct_device_t* select_device(std::vector<libct_device_t*> devices) {
	std::string choice;
	std::cout << "Discovered devices:" << std::endl;
	for (int i = 0; i < devices.size(); ++i) {
		std::cout << i + 1 << ") " << devices[i]->get_name << " : " << devices[i]->get_serial_number << std::endl;
	}
	std::cout << "Enter number of device to connect:" << std::endl;
	while (true) {
		//user input
		std::cin >> choice;
		std::cout << std::endl;
		if (!is_int(choice)) {
			std::cout << "Please enter a number." << std::endl;
			continue;
		}
		int ans = std::stoi(choice);
		if (ans < 1 || ans > devices.size()) {
			std::cout << "Please enter a valid number from the list." << std::endl;
			continue;
		}
		std::cout << "Connecting to device: " << devices[ans - 1] << std::endl;
		// Set device connection logic here
		return devices[ans - 1];
	}
}


int main(int argc, char* argv[]) {
	// I want to make this an argument based program, aka "ctlink.exe discover" to print a list of discoverable devices
	// temp arg printing from stack overflow
	std::cout << "Have " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
	std::cout << std::endl;

	CSV_Provider csv_provider("my_csv.csv", { "hope", "this", "works" });
	csv_provider.append("my,data,to,store");

	// std::vector<libct_device_t*> devices;

	// want to make a better system for handleing errors. maybe dont use the throw syntax? and just cerr out
	try {
		libct_context_t* context = get_init_context();

		discover_devices(context);
		//this should return vector of devices
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	std::cout << "Does not error" << std::endl;

	// Select device for pairing
	// libct_device_t* device = select_device(devices);

	return 0;
}
