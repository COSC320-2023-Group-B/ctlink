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