#pragma once

// this funtion will also accept the collums to be put into the csv
void create_csv_context(int *context, const char *file_name);
void add_data_to_csv(int* context, const char* some_data);