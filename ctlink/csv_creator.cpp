#include <iostream>
#include <fstream>

#include "csv_creator.h"

// also someone needs to move the callback.cpp into the header files directory

std::string join_vector(std::vector<std::string> string_vector, std::string delimiter = ",") {
    std::string joined_string = "";

    for (auto& s : string_vector) {
        joined_string.append(s);
        joined_string.append(delimiter);
    }

    // works for any size delim
    for (auto& _ : delimiter)
        joined_string.pop_back();

    return joined_string;
}

CSV_Provider::CSV_Provider(std::string file_name, std::vector<std::string> headers) {
    csv_file_name = file_name;

    std::string header_string = join_vector(headers);

    std::ofstream myfile;
    myfile.open(csv_file_name);
    myfile << header_string << std::endl;
    myfile.close();

    std::cout << "Made a file" << std::endl;
}

void CSV_Provider::append(std::string some_data) {
    std::ofstream myfile;
    myfile.open(csv_file_name, std::ofstream::out | std::ofstream::app);
    myfile << some_data << std::endl;
    myfile.close();

    std::cout << "your data was totaly written somewhere :)" << std::endl;
}
