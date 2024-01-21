# include <string>
# include <iostream>
# include "Product.h"

using namespace std;

//class Product
//{

    // attributes
//private:
int ProductID;
string ProductName;
double Price;
int QuantityInStock;


// member functions
//public:
    // setters
void Product::SetProductID(int id)
{
    this->ProductID = id;
}

void Product::SetProductName(string name)
{
    this->ProductName = name;
}

void Product::SetPrice(double price)
{
    this->Price = price;
}

void Product::setQuantityInStock(int quantity)
{
    this->QuantityInStock = quantity;
}

// getters

int Product::GetProductID()
{
    return ProductID;
}

string Product::GetProductName()
{
    return ProductName;
}

double  Product::GetPrice()
{
    return Price;
}

int Product::GetQuantityInStock()
{
    return QuantityInStock;
}

void Product::ReadFromFile(ifstream& file)
{
    file >> ProductID >> ProductName >> Price >> QuantityInStock;
}

void Product::DisplayBasicInfo()
{
    cout << "ID: " << ProductID << ", Name: " << ProductName << ", Price: " << Price <<  endl;
}
// Default constructor
Product::Product() : ProductID(0), ProductName(""), Price(0.0), QuantityInStock(0) {}
// Constructor
Product::Product(int id, string& name, int quantity, double price) : ProductID(id), ProductName(name), QuantityInStock(quantity), Price(price) {}