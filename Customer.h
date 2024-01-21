#pragma once
#pragma once
# include <string>

using namespace std;

class Customer
{
private:
    string CustomerName;
    int CustomerID = 0;
    int LastAssignedID = 0;
    string CustomerEmail;

public:
    void SetCustomerName(string name);


    void SetCustomerEmail(string email);

    void SetCustomerID(int id);

    void SetCustomerID();

    string GetCustomerName();

    int GetCustomerID();
  

    string GetCustomerEmail();

};