#pragma once
# include "Product.h"
# include "Order.h"

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
   
    void AddItemToCart(Product product[], int CAPACITY, int id, int quantity);

    void RemoveItemFromCartWithProductID(int id, int quantity);

    void DisplayCartItems();

    void SetTotalItemsInCart(int ItemCount);

    int GetTotalItemsInCart();

    

};