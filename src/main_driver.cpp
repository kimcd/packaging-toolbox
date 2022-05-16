//
//  main.cpp
//  component-database
//
//  Created by Christopher Kim on 5/9/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//

#include <iostream>
#include "SCRATCH.h"
#include "Component.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ios;

#include<sstream>
using std::stringstream;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

void test_component()
{
    design_simple_search_and_data_entry();
}


void test_read_csv() {
    
    string file_path = "/Users/christopherkim/Documents/cpp/packaging-toolbox/src/component_database.csv";
    
    vector<vector<string>> my_csv;
    
    my_csv = read_in_csv2(file_path);
    
    print_vector_vector(my_csv);
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //test_component();
    test_database_manager();
    return 0;
}



