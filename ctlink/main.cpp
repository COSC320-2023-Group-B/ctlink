#include <iostream>
#include <ctlib/caretaker_static.h>

void LIBCTAPI on_device_discovered(libct_context_t* context, libct_device_t* device)
{
	const char* address = libct_device_get_address(device);
	const char* name = libct_device_get_name(device);
	// do something
}

void LIBCTAPI on_device_connected_ready(libct_context_t* context, libct_device_t* device)
{
	// do something
}

void LIBCTAPI on_device_disconnected(libct_context_t* context, libct_device_t* device)
{
	// do something
}

void LIBCTAPI on_data_received(libct_context_t* context, libct_device_t* device, libct_stream_data_t* data)
{
	// handle data
}

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
	//   on_device_discovered()
	//   on_device_connected_ready()
	//   on_device_disconnected()
	//   on_data_received()
	int status = libct_init(&context, &init_data, &callbacks);
	if (LIBCT_FAILED(status)) {
		// Handle error
		std::cerr << "Error: Failed to intialise caretaker context";
	}
	else {
		std::cout << "Successfully initialised caretaker context!";
	}


	return 0;
}