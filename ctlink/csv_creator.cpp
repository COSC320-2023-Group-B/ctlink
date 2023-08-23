#include <iostream>
#include <fstream>

#include "csv_creator.h"


// also someone needs to move the callback.cpp into the header files directory

void create_csv_context(int* context, const char* file_name) {
    // this function will provide a context (some struct) that initalises (or finds) a csv file that can be contiguassly written to

    std::ofstream myfile;
    myfile.open(file_name);
    myfile << "header,line,in,csv\n";
    myfile << "a,b,c,d,\n";
    myfile << "c,s,v,\n";
    myfile << "1,2,3.456\n";
    myfile << "semi;colon";
    myfile.close();

    std::cout << "Made a file" << std::endl;
}

void add_data_to_csv(int* context, const char* some_data) {
    // open filename witch is stored in the context, and write a line to the end.
    // this might have to wait on the file to be ready, so we'll want to store the incomeing data to a buffer and asnc write to the file

    std::cout << "your data was totaly written somewhere :)" << std::endl;
}
