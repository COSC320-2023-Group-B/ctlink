#pragma once
#include <vector>

struct CSV_Context {
	std::string file_name;
	std::vector<std::string> headers;
};

// this funtion will also accept the collums to be put into the csv
void create_csv_context(CSV_Context *context, std::string file_name, std::vector<std::string> headers);
void add_data_to_csv(CSV_Context *context, std::string some_data);