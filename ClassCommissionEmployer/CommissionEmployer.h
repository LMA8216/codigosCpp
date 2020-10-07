#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>

class CommissionEmployer
{
private:
    
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployer(const std::string &, const std::string &,
        const std::string &, double = 0.0, double = 0.0);
    
    void setFirstName( const std::string &);
    std::string getFirstName() const;

    void setLastName( const std::string &);
    std::string getLasttName() const;

    void setSocialSecurityNumber( const std::string &);
    std::string getSocialSecurityNumber() const;

    void setGrossSale(double);
    double getGrossSale() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    double earning() const;
    void print() const;

};  


#endif