#include <string>
#include "Customer.h"

using namespace std;

void Customer::SetCustomerName(string name)
{
    this->CustomerName = name;
}

void Customer::SetCustomerEmail(string email)
{
    this->CustomerEmail = email;
}

string Customer::GetCustomerName()
{
    return CustomerName;
}

void Customer::SetCustomerID()
{
    CustomerID = LastAssignedID++;
}

int Customer::GetCustomerID()
{
    return CustomerID;
}

string Customer::GetCustomerEmail()
{
    return CustomerEmail;
}
