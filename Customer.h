#pragma once
#pragma once
#include <string>

using namespace std;

class Customer
{
private:
    string CustomerName;
    int CustomerID = 0;
    int LastAssignedID = 1;
    string CustomerEmail;

public:
    void SetCustomerName(string name);

    void SetCustomerEmail(string email);

    void SetCustomerID();

    string GetCustomerName();

    int GetCustomerID();

    string GetCustomerEmail();
};