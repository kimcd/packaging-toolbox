/*
 Class to compute Steinberg values.
 
 */

#ifndef Steinberg_h
#define Steinberg_h

#include "Component.h"

class Steinberg
{
public:
    
    static const double CONSTANT;
    
    /*
     @brief Component types, BGA, LCCC, MLCCC, SMSC, SMT, MELF, QFP, CCGA
     */
    enum class Component_type
    {
        AXIAL, // 0.75, MELF,
        DIP, // 1.0,
        
        BGA, // 1.75,
        LCCC, // 2.25
    };
    
    
    Steinberg(const double B,
              const Steinberg::Component_type,
              const double h,
              const double r,
              const double L);
    
    
private:
    double z_inf_rv;  // max displacement for 20 million cycles of RV 
    
};
/*
double calculate_z_inf(const double B, const Steinberg::Component_type, const double h, const double r, const double L);
*/
#endif /* Steinberg_h */
