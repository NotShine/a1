# include <string>
# include "Customer.h"



using namespace std;



//class Customer
//{
//private:
//    string CustomerName;
//    int CustomerID;
//    string CustomerEmail;

//public:
void Customer::SetCustomerName(string name)
{
    this->CustomerName = name;
}

void Customer::SetCustomerEmail(string email)
{
    this->CustomerEmail = email;
}

void Customer::SetCustomerID(int id)
{
    this->CustomerID = id;
}
string Customer::GetCustomerName()
{
    return CustomerName;
}

int Customer::GetCustomerID()
{
    return CustomerID;
}

string Customer::GetCustomerEmail()
{
    return CustomerEmail;
}
//};