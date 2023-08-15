#include <iostream>
#include <ctlib/caretaker_static.h>

#include "callback.h"

int main() {
	libct_context_t* context = NULL;

	libct_init_data_t init_data;
	memset(&init_data, 0, sizeof(init_data));
	init_data.device_class = LIBCT_DEVICE_CLASS_BLE_CARETAKER4;

	libct_app_callbacks_t callbacks = { 0 };
	callbacks.on_device_discovered = on_device_discovered;
	callbacks.on_device_connected_ready = on_device_connected_ready;
	callbacks.on_device_disconnected = on_device_disconnected;
	callbacks.on_data_received = on_data_received;

	// libct_init requires a pointer to an empty context, initialisation data, and callback functions
	// callback functions must implement the following functions at least, and the non-implemented must be NULL:
	// on_device_discovered(context, device);
	// on_device_connected_ready(context, device);
	// on_device_disconnected(context, device);
	// on_data_received(context, device, data);
	int status = libct_init(&context, &init_data, &callbacks);
	if (LIBCT_FAILED(status)) {
		// Handle error
		std::cerr << "Error: Failed to initialise caretaker context" << std::endl;

		// can you handle this error? just crash
		return 1;
	}
	
	std::cout << "Successfully initialised caretaker context!" << std::endl;

	libct_start_discovery(context, 20000);

	return 0;
}