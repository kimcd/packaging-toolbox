
#include "Component.h"

#include <iostream>
using std::ostream;
using std::cerr;
using std::endl;
using std::cout; 

#include <string>
using std::string;

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
