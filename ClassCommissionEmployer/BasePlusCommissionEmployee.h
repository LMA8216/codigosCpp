#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployer.h"

class BasePlusCommissionEmployee : CommissionEmployer
{
private:
    double baseSalary;
    
public:
    BasePlusCommissionEmployee ( const std::string &, const std::string &,
        const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary( double ); // set base salary
    double getBaseSalary() const;

    double earnings() const;
    void print() const;
};


#endif