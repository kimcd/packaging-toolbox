//
//  SCRATCH.cpp
//  component-database
//
//  Created by Christopher Kim on 5/9/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//
#include "Component.h"
#include "SCRATCH.h"
#include <vector>
#include "Database_Manager.h"
using std::vector;

#include <string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ios;
using std::fstream;

#include<sstream>
using std::stringstream;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

#include <regex>

#include <algorithm>
using std::transform;

#include <cctype>
using std::tolower;


void search_part_csv(string part_number)
{
    string file_path = "/Users/christopherkim/Documents/cpp/component-database/component-database/component_database.csv";
    
    vector<vector<string>> comp_data;
    
    comp_data = read_in_csv(file_path);
    
    // search first
    char regex_part_number[] = "[a-zA-Z_][a-zA-Z_0-9]*\\.[a-zA-Z0-9]+";
    
    
}

void print_vector_vector(vector<vector<string>>& vector)
{
    for(auto& vec : vector)
    {
        for(auto& ele : vec)
        {
            cerr << ele << ", ";
        }
        cerr << "\n";
    }
}

void print_vector(vector<string>& vector)
{
    for(auto& ele : vector)
    {
        cerr << ele << ", ";
    }
}


void search_database_for_match(vector<string>& token)
{
    string database_file_path = "/users/christopherkim/documents/cpp/packaging-toolbox/src/component_database_.csv";
    
    vector<vector<string>> database_csv;
    database_csv = read_in_csv2(database_file_path);
    
    for(const auto& row : database_csv)
    {
        if(token[1] == row[0])
        {
            cerr << "match found: " << token[1] << " == " << row[0] << endl;
            token.insert(token.end(), row.begin() + 1, row.end());
            //return true;
            break;  // repeated entries in the database will be overlooked!!
        } else
        {
            cerr << token[1] << " does not match " << row[0] << endl;
        }
    }
    //return false;
}

// Design for searching a worksheet list of part numbers and populating with entries from
// the component_database 
void design_simple_search_and_data_entry()
{
    string file_path = "/Users/christopherkim/Documents/cpp/packaging-toolbox/src/component_worksheet.csv";
    
    
    vector<vector<string>> my_csv;
    
    my_csv = read_in_csv2(file_path);
    
    
    vector<string> token;
    
    fstream fout;
    fout.open("/Users/christopherkim/Documents/cpp/packaging-toolbox/src/component_worksheet_new.csv", ios::out);
    
    // search if components in component list exist in database. if yes, fill in data in component_worksheet.csv
    for(auto& row : my_csv)
    {
        token.clear();
        token.insert(token.begin(), row.begin(), row.end());
        
        cout << "searching for match for: " << token[1] << endl;
        
        // Note: components without a match in the database, will simply be
        //       left unmodified
        search_database_for_match(token);
        
        size_t i;
        
        for(i = 0; i < token.size() - 1; ++i)
        {
            fout << token[i] << ",";
        }
        
        // final row entry will end with newline character instead of comma
        fout << token[i] << "\n";
        
    }
    
    // close the file
    fout.close();
    
    // delete the worksheet
    // rename the new file with the worksheetname 
    
}

vector<vector<string>> read_in_csv2(const string& file_path)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (file_path, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
            
            stringstream str(line);
            
            while(getline(str, word, ','))
                row.push_back(word);
                content.push_back(row);
                }
    }
    else
    cerr<<"Could not open the file\n";
    
    return content; 
}


vector<vector<string>> read_in_csv(const string& file_path)
{
    
    ifstream input_file;
    
    input_file.open(file_path, ios::in);
    
    if(!input_file)
    {
        cerr << "file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    
    
    string line;
    string column_name;
    vector<vector<string>> result;
    vector<string> temp_vec;
    string val;
    
    // Read the column names
    if(input_file.good())
    {
        // Extract the first line in the file
        std::getline(input_file, line);
        
        // Create a stringstream from line
        stringstream ss(line);
    }
    
    //int line_no = 0;
    
    // Toss the data headers by doing nothing with ss
    // Read data, line by line
    while(std::getline(input_file, line))
    {
        //cout << "line_no: " << line_no << endl;
        //line_no++;
        // Create a stringstream of the current line
        std::stringstream ss(line);
        
        // Keep track of the current column index
        //int colIdx = 0;
        
        // Extract each integer
        while(ss >> val){
            
            // Add the current integer to the 'colIdx' column's values vector
            temp_vec.push_back(val);
            
            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();
            
            // Increment the column index
            //colIdx++;
            
        }
        
        result.push_back(temp_vec);
        temp_vec.clear();
        
    }
    // Close file
    input_file.close();
    
    return result;
}  // end read_elevator_csv

void test_database_manager()
{
    Database_Manager dm;
    dm.lowercase(); 
    dm.print_database();
    dm.rewrite_database();
    
}
