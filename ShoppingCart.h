#pragma once
# include "Product.h"

const int SIZE = 20;
using namespace std;

class ShoppingCart
{

private:
    static const int MAX_CART_ITEMS = 15;
    int TotalItemsInCart = 0;


    // int ItemCount = 0;
    double TotalCostOfItemsInCart = 0;

    int Quantity = 0;

public:
    Product products[SIZE];

    //Product CartItems[MAX_CART_ITEMS];
    // int TotalItemsInCart = 0;

   //  ShoppingCart() : TotalItemsInCart(0), TotalCostOfItemsInCart(0) {}

    void AddItemToCart(int  id, int quantity);

    void RemoveItemFromCartWithProductID(int productID);

    void RemoveItemFromCartWithProductName(string productName);

    void DisplayCartItems();

    void SetTotalItemsInCart(int ItemCount);

    int GetTotalItemsInCart();



};