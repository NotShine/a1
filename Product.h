#pragma once
# include <fstream>

using namespace std;

class Product
{

    // attributes
private:
    int ProductID;
    string ProductName;
    double Price;
    int QuantityInStock;
    int QuantityAddedToCart;
    int ProductIDAddedToCart;
        
    // member functions
public:
    // setters
    void SetProductID(int id);


    void SetProductName(string name);


    void SetPrice(double price);

    void setQuantityInStock(int quantity);

    void SetQuantityAddedToCart(int quantity);

    void SetProductIDAddedToCart(int id);

    // getters

    int GetProductID();


    string GetProductName();

    double GetPrice();


    int GetQuantityInStock();

    int GetQuantityAddedToCart();

    int GetProductIDAddedToCart();


    void ReadFromFile(ifstream& file);


    void DisplayBasicInfo();


    // Default constructor
    Product(); //: ProductID(0), ProductName(""), Price(0.0) {}
    // Constructor
    Product(int id, string& name, int quantity, double price); //: ProductID(id), ProductName(name), QuantityInStock(quantity), Price(price) {}
};