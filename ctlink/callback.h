// callback.h
#pragma once
#include <ctlib/caretaker_static.h>

extern "C" {
    void LIBCTAPI on_device_discovered(libct_context_t* context, libct_device_t* device);
    void LIBCTAPI on_device_connected_ready(libct_context_t* context, libct_device_t* device);
    void LIBCTAPI on_device_disconnected(libct_context_t* context, libct_device_t* device);
    void LIBCTAPI on_start_measuring(libct_context_t* context, libct_device_t* device, int status);
    void LIBCTAPI on_data_received(libct_context_t* context, libct_device_t* device, libct_stream_data_t* data);
}
