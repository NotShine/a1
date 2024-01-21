# include <iostream>
# include <string>

# include "ShoppingCart.h"
# include "Product.h"


static const int CAPACITY = 20;


using namespace std;




int ItemCount = 0; // number of items in cart

void ShoppingCart::SetTotalItemsInCart(int totalItemsInCart) {
    this->TotalItemsInCart = totalItemsInCart;
}

int ShoppingCart::GetTotalItemsInCart() {
    return TotalItemsInCart;
}


void ShoppingCart::AddItemToCart(int id, int quantity) {
    if (TotalItemsInCart < MAX_CART_ITEMS) {
        products[TotalItemsInCart].SetProductID(id);
        products[TotalItemsInCart].setQuantityInStock(quantity);
        TotalItemsInCart++;
        cout << "Product added to cart" << endl;
        cout << "Number of products in your cart: " << TotalItemsInCart << endl;

        ItemCount += quantity;
        cout << "Quantity of products added to cart " << ItemCount << endl;

        // Update the quantity in stock of the product
        products[id].setQuantityInStock(products->GetQuantityInStock() - quantity);


    }
    else {
        cout << "Shopping cart is full!" << endl;
    }
}





void ShoppingCart::RemoveItemFromCartWithProductID(int productID)
{
    for (int i = 0; i < ItemCount; i++)
    {
        if (products[i].GetProductID() == productID)
        {
            // TotalCostOfItemsInCart -= CartItems[i].GetPrice();
            cout << "Removed " << products[i].GetProductName() << " from cart" << endl;

            for (int j = i; j < TotalCostOfItemsInCart - 1; j++)
            {
                products[j] = products[j + 1];
            }

            --TotalItemsInCart;
        }
    }

    cout << "Product not found" << endl;
}

void ShoppingCart::RemoveItemFromCartWithProductName(string productName) // wont use this one
{
    for (int i = 0; i < ItemCount; i++)
    {
        if (products[i].GetProductName() == productName)
        {
            //   TotalCostOfItemsInCart -= CartItems[i].GetPrice();
            cout << "Removed " << products[i].GetProductName() << " from cart" << endl;

            for (int j = i; j < TotalCostOfItemsInCart - 1; j++)
            {
                products[j] = products[j + 1];
            }

            --TotalItemsInCart;
        }
    }

    cout << "Product not found" << endl;
}




// display cart items
void ShoppingCart::DisplayCartItems() {
    cout << "Items in Cart:" << endl;

    for (int i = 0; i < TotalItemsInCart; i++) {
        cout <<" Product: "<< products[i].GetProductName() << "  " << "Price: " << products[i].GetPrice() << endl;
    }
}

