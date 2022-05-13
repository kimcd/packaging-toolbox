

#ifndef Component_h
#define Component_h

#include <iostream>

class Component
{
    
    friend std::ostream& operator<<(std::ostream& output, Component& component);
    
public:
    
    enum class Package_type
    {
        NA = -1,
        LCCC,
        QFP,
        CCGA,
        BGA,
        MELF,
        RES,
        MLCCC,
        STSMC,  // stacked cap
        QFN,  // quad no-leads
        DIP,  // dual-inline
        TO
    };
    
    
    Component(std::string part_number,
              Component::Package_type package_type,
              double length,
              double width);
    
    

    inline std::string get_part_number() const
    {
        return part_number;
    }
    
    
    inline double get_x() const
    {
        return x;
    }
    
    
    inline double get_y() const
    {
        return y;
    }
    
    /*
     @brief Overriding the copy assignment for troubleshooting
     */
    Component(const Component& rhs);
    
    /*
     @brief Overriding the copy constructor for troubleshooting
     */
    Component& operator=(const Component& rhs);
    
    
    
private:
    std::string part_number;
    Component::Package_type package_type;
    double x;  // width
    double y;  // length 
    
};

#endif /* Component_h */
