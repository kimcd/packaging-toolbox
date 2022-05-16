//
//  Database_Manager.cpp
//  packaging-toolbox
//
//  Created by Christopher Kim on 5/14/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//

#include "Database_Manager.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ios;
using std::fstream;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <algorithm>
using std::transform; 

#include <cctype>
using std::tolower;


//const char Database_Manager::DATABASE_FILEPATH[] = "/users/christopherkim/documents/cpp/packaging-toolbox/src/component_database_.csv";
const char Database_Manager::DATABASE_FILEPATH[] = "/Users/kimcd1/git/packaging-toolbox/src/component_database_.csv";

Database_Manager::Database_Manager()
:database(read_database())
{
    // empty body
}


bool Database_Manager::search_component(vector<string>& token)
{
    
    for(const auto& row : database)
    {
        if(token[0] == row[0])
        {
            cerr << "match found: " << token[0] << " == " << row[0] << endl;
            token = row;
            return true;
        } else
        {
            cerr << token[0] << " does not match " << row[0] << endl;
        }
    }
    return false;
}


// should return vector of Component objects
vector<vector<string>> read_database()
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    
    fstream file (Database_Manager::DATABASE_FILEPATH, ios::in);
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


void Database_Manager::lowercase()
{
    for(auto& row : database)
    {
        int pn_field = static_cast<int>(Database_Manager::Field::PART_NUMBER);
        
        transform(row[pn_field].begin(),
                  row[pn_field].end(),
                  row[pn_field].begin(),
                  [](unsigned char c)
        {
            return tolower(c);
            
        });
    }
}


void Database_Manager::rewrite_database() const
{
    fstream fout;
    // for macbook
    //char temp_filepath[] = "/Users/christopherkim/Documents/cpp/packaging-toolbox/src/temp.csv";
    //char component_database_filepath[] = "/Users/christopherkim/Documents/cpp/packaging-toolbox/src/component_database_.csv";

    char temp_filepath[] = "/Users/kimcd1/git/packaging-toolbox/src/temp.csv";
    char component_database_filepath[] = "/Users/kimcd1/git/packaging-toolbox/src/component_database_.csv";

    fout.open(temp_filepath, ios::out);

    for(auto& row : database)
    {
        size_t i;
        
        for(i = 0; i < row.size() - 1; ++i)
        {
            fout << row[i] << ",";
        }
    
        // final row entry will end with newline character instead of comma
        fout << row[i] << "\n";
    
    }

    // close the file
    fout.close();
    
    // removing the existing file
    remove(component_database_filepath);
    
    // renaming the updated file with the existing file name
    rename(temp_filepath,
    		component_database_filepath);
    
}


void Database_Manager::print_database() const
{
    for (auto& row : database)
    {
        for (auto& field : row)
        {
            cout << field << ",";
        }
        
        cout << "\n";
    }
}
