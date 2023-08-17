#include <iostream>
#include <cstdio>
#include "callback.h"

void LIBCTAPI on_device_discovered(libct_context_t* context, libct_device_t* device)
{
	const char* address = libct_device_get_address(device);
	const char* name = libct_device_get_name(device);

	// line for when it is called:
	std::cout << "on_device_discovered Called" << std::endl;

	// device information
	std::cout << "Name: " << name << std::endl << "Address: " << address << std::endl;

	// connect to first avialable device, change to whitelist later
	libct_stop_discovery(context);
	libct_connect(context, device);
}

void LIBCTAPI on_device_connected_ready(libct_context_t* context, libct_device_t* device)
{
	std::cout << "on_device_connected_ready Called" << std::endl;

	// we only need a couple of these, but just for testing perposes, use all
	int flags = (LIBCT_MONITOR_INT_PULSE |
				 LIBCT_MONITOR_PARAM_PULSE |
				 LIBCT_MONITOR_VITALS |
				 LIBCT_MONITOR_CUFF_PRESSURE |
				 LIBCT_MONITOR_DEVICE_STATUS |
				 LIBCT_MONITOR_BATTERY_INFO);

	// wait until user ready, to proceade

	// windows only function
	std::cout << "Device ready to connect" << std::endl;
	system("pause");

	libct_start_monitoring(context, flags);
}

void LIBCTAPI on_device_disconnected(libct_context_t* context, libct_device_t* device)
{
	// do something

	std::cout << "on_device_disconnected Called" << std::endl;
}

void LIBCTAPI on_start_measuring(libct_context_t* context, libct_device_t* device, int status)
{
	// do something

	std::cout << "on_start_measuring Called" << std::endl;


	// dont know what the status int is

	// need to calibrate the thing
	libct_cal_t cal = { 0 };
	cal.type = LIBCT_AUTO_CAL;

	// ???, posture is a werid thing to ask for, may have to get user imput at runtime for this
	libct_posture_t posture = LIBCT_POSTURE_SITTING; // LIBCT_POSTURE_SUPINE

	cal.config.auto_cal.posture = posture;
	libct_start_measuring(context, &cal);
}

void LIBCTAPI on_data_received(libct_context_t* context, libct_device_t* device, libct_stream_data_t* data)
{
	// handle data

	std::cout << "on_data_received Called" << std::endl;
}