#include <iostream>
#include <string>

#include "ShoppingCart.h"
#include "Product.h"

static const int CAPACITY = 20;

using namespace std;

int ItemCount = 0; // number of items in cart

void ShoppingCart::SetTotalItemsInCart(int totalItemsInCart)
{
	this->TotalItemsInCart = totalItemsInCart;
}

int ShoppingCart::GetTotalItemsInCart()
{
	return TotalItemsInCart;
}

void ShoppingCart::AddItemToCart(Product product[], int CAPACITY, int id, int quantity) {
	if (TotalItemsInCart < MAX_CART_ITEMS) {
		bool productFound = false;

		for (int i = 0; i < CAPACITY; i++) {
			if (product[i].GetProductID() == id) {
				productFound = true;

				if (product[i].GetQuantityInStock() >= quantity) {
					products[TotalItemsInCart] = product[i];
					TotalItemsInCart++;

					cout << "Product added to cart" << endl;
					cout << "Number of products in your cart: " << TotalItemsInCart << endl;

					ItemCount += quantity;
					cout << "Quantity of product with id " << id << "  added to cart: " << ItemCount << endl;

					product[i].setQuantityInStock(product[i].GetQuantityInStock() - quantity);

					break;
				}
				else {
					cout << "Not enough quantity in stock" << endl;
					break;  // Exit the loop if quantity is not sufficient
				}
			}
		}

		if (!productFound) {
			cout << "Product not found" << endl;
		}
	}
	else {
		cout << "Cart is full" << endl;
	}
}


void ShoppingCart::RemoveItemFromCartWithProductID(int id, int quantityToremove)
{
	bool productFound = false;

	for (int i = 0; i < TotalItemsInCart; ++i)
	{
		if (products[i].GetProductID() == id)
		{
			productFound = true;

			if (quantityToremove <= products[i].GetQuantityInStock())
			{
				// Decreasing quantity of product in cart/removing it
				TotalItemsInCart -= quantityToremove;  // Subtract only the quantity being removed

				cout << "Product with ID " << id << " removed from cart" << endl;
				cout << "Number of products in cart is: " << TotalItemsInCart << endl;

				// Updating stock
				products[i].setQuantityInStock(products[i].GetQuantityInStock() - quantityToremove); // this does not work as expected

				// Remove the product from the cart if its quantity becomes 0
				if (products[i].GetQuantityInStock() == 0)
				{
					// Updating the products array
					for (int j = i; j < TotalItemsInCart - 1; ++j)
					{
						products[j] = products[j + 1];
					}
					--TotalItemsInCart;
				}

				break;
			}
			else
			{
				cout << "Quantity to remove exceeds the quantity in cart for Product with ID " << id << endl;
				break;
			}
		}
	}

	if (!productFound)
	{
		cout << "Product with ID " << id << " not found in the cart." << endl;
	}
}


// display cart items
void ShoppingCart::DisplayCartItems()
{

	if (TotalItemsInCart == 0)
	{
		cout << "Your shopping cart is empty" << endl;
	}
	cout << "Items in Cart:" << endl;

	for (int i = 0; i < TotalItemsInCart; i++)
	{
		cout << " Product N0: " << i + 1 << "  "
			<< "Name: " << products[i].GetProductName() << "  "
			<< "Price: " << products[i].GetPrice() << "  "
			<< "ID: " << products[i].GetProductID() << "  "
			<< "Number you added to cart: " << ItemCount << endl;
	}

	
}
