# include <string>
# include <iostream>
# include <iomanip>

# include "Product.h"

using namespace std;



//private attributes
int ProductID;
string ProductName;
double Price;
int QuantityInStock;
//int QuantityAddedToCart;
//int ProductIDAddedToCart;



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
    cout <<setw(2)<< "ID: " << setw(2) << ProductID << ", Name: "<<setw(2) << ProductName << setw(2) << ", Price: " << Price <<  endl;
}
// Default constructor
Product::Product() : ProductID(0), ProductName(""), Price(0.0), QuantityInStock(0) {}
// Constructor
Product::Product(int id, string& name, int quantity, double price) : ProductID(id), ProductName(name), QuantityInStock(quantity), Price(price) {}