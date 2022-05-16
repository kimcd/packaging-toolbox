/*
 COMPONENT TYPES
 Discrete
    - Transistor
        - jfet, mosfet, bipolar transistor, optocoupler,
    - Diode
        - rectifier, zener, fet, schottky,
 Monolithic Microcircuit
 Relay
 Magnetic
    - Inductor
 Hybrid Microcircuit
 
 PACKAGE TYPES
 - Prefer per mil-spec nomenclature (ex: MIL-STD-1835 figure 1, CDFP3-F10)
 - OR https://en.wikipedia.org/wiki/List_of_integrated_circuit_packaging_types
 
 
 */

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
    
    enum class Part_type
    {
        NA = -1,
        XTAL_OSC,
        MICRO_HYBRID,  // hybrid microcircuit
        MICRO_MONO,  // monolithic microcircuit
        MICRO_PEM,  // PEM microcircuit
        DISCRETE_DIODE,  // Discrete semiconductor device: diode
        RESISTOR_G311P672,
        RESISTOR_G311P683,
        RESISTOR_G311P472,
        RESISTOR_RBR,
        RESISTOR_RWR,
        RESISTOR_RCR,
        RESISTOR_RER,
        RESISTOR_RTR,
        RESISTOR_RLR,
        RESISTOR_RNX,
        RESISTOR_RM,  // fixed film resistor chip
        RESISTOR_RZ
    };
    
    Component(std::vector<std::vector<std::string>>& data);
    
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
    Component::Part_type part_type;
    Component::Package_type package_type;
    double x;  // width
    double y;  // length 
    double vendor_max_temp;
    
};

#endif /* Component_h */
