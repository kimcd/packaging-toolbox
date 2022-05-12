//
//  SCRATCH.cpp
//  component-database
//
//  Created by Christopher Kim on 5/9/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//

#include "SCRATCH.h"
#include <vector>
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

#include <regex>


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

