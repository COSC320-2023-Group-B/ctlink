#include <iostream>
#include <fstream>

#include "csv_creator.h"
#include <cassert>



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


void create_csv_context(CSV_Context* context, std::string file_name, std::vector<std::string> headers) {
    // this function will provide a context (some struct) that initalises (or finds) a csv file that can be contiguassly written to

    context->file_name = file_name;
    context->headers = headers;

    // this line issent working? headers must be non zero
    // assert(headers.size > 0);

    std::string header_string = join_vector(context->headers);

    std::ofstream myfile;
    myfile.open(context->file_name);
    myfile << header_string.c_str() << std::endl;
    myfile.close();

    std::cout << "Made a file" << std::endl;
}

void add_data_to_csv(CSV_Context* context, std::string some_data) {
    // open filename witch is stored in the context, and write a line to the end.
    // this might have to wait on the file to be ready, so we'll want to store the incomeing data to a buffer and asnc write to the file

    std::ofstream myfile;
    myfile.open(context->file_name, std::ofstream::out | std::ofstream::app);
    myfile << some_data.c_str() << std::endl;
    myfile.close();

    std::cout << "your data was totaly written somewhere :)" << std::endl;
}
