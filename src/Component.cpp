/*
 Wishlist (prioritized - find the most powerful and bite-sized.)
 - Perform a Steinberg analysis given all parameters.
 - [x] Feed a list of part numbers, auto-generate component data.
 - Feed a csv of previous parts and append to the database.csv.
 - basic data for now: part number, part type, package type, derated temp, temp

 4.
 
 Functions to carry out the wishlist
 1. some.csv contains a list of part numbers (one per line). Read it in. Search
    against the database.csv, find a match and write to some.csv the additional
    values that you'd need to perform analysis (package type, max junction,
    derated temperature, theta jb, theta jc,
 
 2. database.
 

 
 */

#include "Component.h"

#include <iostream>
using std::ostream;
using std::cerr;
using std::endl;
using std::cout; 

#include <string>
using std::string;

#include <vector>
using std::vector;

Component::Component(vector<vector<string>>& data)
{
    
}


// Maybe instead of this, pass a Component_Database object?
Component::Component(string part_number,
                     Component::Package_type package_type,
                     double length,
                     double width)
:part_number(part_number), package_type(package_type), x(length), y(width)
{
    // empty body 
}


ostream& operator<<(ostream& output, Component& component)
{
    output
    << component.get_part_number()
    << " length == " << component.get_x()
    << "width == " << component.get_y() << endl;
    
    return output;
}
