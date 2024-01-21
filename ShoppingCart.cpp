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



void ShoppingCart::AddItemToCart(Product product[], int CAPACITY, int id, int quantity) {
	if (TotalItemsInCart < MAX_CART_ITEMS) {
		bool productFound = false;

		for (int i = 0; i < CAPACITY; i++) {
			if (product[i].GetProductID() == id) {
				productFound = true;

				products[TotalItemsInCart] = product[i];
				TotalItemsInCart++;

				cout << "Product added to cart" << endl;
				cout << "Number of products in your cart: " << TotalItemsInCart << endl;

				ItemCount = +quantity;
				cout << "Quantity of product with id " << id << "  added to cart: " << ItemCount << endl;

				product[i].setQuantityInStock(product[i].GetQuantityInStock() - quantity);

				break;
			}
			else if (productFound) {
				cout << "Product not found" << endl;
			}
		}
	}
	else {
		cout << "Cart is full" << endl;
	}
}




void ShoppingCart::RemoveItemFromCartWithProductID(int id, int quantity)
{
	bool productFound = false;
	for (int i = 0; i < ItemCount; i++)
	{
		if (products[i].GetProductID() == id)
		{
			productFound = true;

			if (quantity >= products[i].GetQuantityInStock())
			{
				//decreasing quantity of product in cart/ removing it
				TotalItemsInCart -= products[i].GetQuantityInStock(); //total products

				cout << "Product with " << id << " removed from cart" << endl;
				cout << "Number of products in cart is: " << TotalItemsInCart << endl;
			}

			else {
				ItemCount -= quantity;
			}
			//updating stock
			products[i].setQuantityInStock(products[i].GetQuantityInStock() + quantity);


			// Remove the product from the cart if its quantity becomes 0
			if (products[i].GetQuantityInStock() == 0) {

				//updating the products array
				for (int j = i; j < TotalItemsInCart - 1; ++j) {
					products[j] = products[j + 1];
				}
				--TotalItemsInCart;
			}

			break;
		}
	}

	if (productFound) {       // if (false) 
		cout << "Product with ID " << id << " not found in the cart." << endl;
	}
}







// display cart items
void ShoppingCart::DisplayCartItems() {

	if (TotalItemsInCart == 0) {
		cout << "Your shopping cart is empty" << endl;
	}
	cout << "Items in Cart:" << endl;

	for (int i = 0; i < TotalItemsInCart; i++) {
		cout << " Product: " << i + 1<<"  " << products[i].GetProductName() << "  " << "Price: " << products[i].GetPrice() << endl;
	}

	cout << "Total quantity in cart is: " << TotalItemsInCart << endl;
}

