#include <iostream>
#include <cstdio>
#include "callback.h"

void LIBCTAPI on_device_discovered(libct_context_t* context, libct_device_t* device)
{
	const char* address = libct_device_get_address(device);
	const char* name = libct_device_get_name(device);
	// do something

	// line for when it is called:
	std::cout << "on_device_discovered Called" << std::endl;

	// debug information
	std::cout << "Name: " << name << std::endl << "Address: " << address << std::endl;
}

void LIBCTAPI on_device_connected_ready(libct_context_t* context, libct_device_t* device)
{
	// do something

	std::cout << "on_device_connected_ready Called" << std::endl;
}

void LIBCTAPI on_device_disconnected(libct_context_t* context, libct_device_t* device)
{
	// do something

	std::cout << "on_device_disconnected Called" << std::endl;
}

void LIBCTAPI on_data_received(libct_context_t* context, libct_device_t* device, libct_stream_data_t* data)
{
	// handle data

	std::cout << "on_data_received Called" << std::endl;
}