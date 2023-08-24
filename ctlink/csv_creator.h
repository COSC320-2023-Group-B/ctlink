#pragma once
#include <vector>

class CSV_Provider {
	std::string csv_file_name;

public:
	CSV_Provider(std::string file_name, std::vector<std::string> headers);
	void append(std::string some_data);
};