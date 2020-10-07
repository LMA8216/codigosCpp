#include <iostream>
#include <stdexcept>
#include "CommissionEmployer.h"

using namespace std;

CommissionEmployer::CommissionEmployer(
    const string &first, const string &last, const string &ssn,
    double sales, double rate)
{

    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSale( sales );
    setCommissionRate( rate );
}


void CommissionEmployer::setFirstName( const string &first){
    firstName = first;
}

string CommissionEmployer::getFirstName() const{
    return firstName;
}

void CommissionEmployer::setLastName( const string &last){
    lastName = last;
}

string CommissionEmployer::getLasttName() const{
    return lastName;
}

void CommissionEmployer::setSocialSecurityNumber( const string &ssn){
    socialSecurityNumber = ssn;
}

string CommissionEmployer::getSocialSecurityNumber() const{
    return socialSecurityNumber;
}

void CommissionEmployer::setGrossSale(double sales)
{
    if (sales >= 0.0)
    {
        grossSales = sales;
    }
    else
    {
        throw invalid_argument("Gross sales must be >= 0.0");
    }    
}

double CommissionEmployer::getGrossSale() const
{
    return grossSales;
}

void CommissionEmployer::setCommissionRate( double rate )
{
    if ( rate > 0.0 && rate < 1.0 )
        commissionRate = rate;
    else
        throw invalid_argument( "Commission rate must be > 0.0 and < 1.0" );
} // end function setCommissionRate
// return commission rate
double CommissionEmployer::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

// calculate earnings
double CommissionEmployer::earning() const
{
    return commissionRate * grossSales;
} // end function earnings
// print CommissionEmployee object
void CommissionEmployer::print() const
{
    cout << "commission employee: " << firstName << ' ' << lastName
    << "\nsocial security number: " << socialSecurityNumber
    << "\ngross sales: " << grossSales
    << "\ncommission rate: " << commissionRate;
} 