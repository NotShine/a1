#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype> // Include the cctype header for tolower function
#include <stdlib.h>
#include <ctime>
#include <algorithm>

# include "Product.h"
# include  "Order.h"
# include "Customer.h"
# include "Shoppingcart.h"


using namespace std;


static const int MAX_PRODUCTS = 20;

void DisplayAvailableStock(Product products[]); // prints all products

void SearchUsingRange(int range, Product product[]); // searches for products in desired price range

void SearchUsingProductID(int id, Product products[]); // searches for products using id

void SortByAscendingPrice(Product* product, int size); // sorts products in ascending order

void PrintPriceRangeMenu(); // print the menu for selected price range, users can select options

void PrintMenuOptions(); // prints the general menu at program start

void PrintShoppingCartMenu(); // printts the shopping cart menu (view, remove products, checkout)

bool IsNameValid(string name); // checks if name of user is valid (input validation)

void CheckQuantity(int quantity, int id); // checks if input quantity is <= stock quantity / AddToCart function is then called



ShoppingCart cart; // instance of Shopping cart class, access functions


Product product[MAX_PRODUCTS]; // create an array of Product objects, store data

Order orderOne; // Order instance

int main()
{

	int id, i = 0, quantity = 0, CustomerID;
	double price = 0;
	string name, email;

	Customer customerOne;

	cout << "Welcome to Treasure Traders" << endl << endl;

	do // code runs in a do while loop allowing for continuation
	{
		//customer name
		cout << "Enter your name: ";
		getline(cin, name);

		// Validate the input
		if (!IsNameValid(name))
		{
			cout << "Invalid input. Please enter a valid name." << endl;
		}
	} while (!IsNameValid(name));

	     // customer email
	cout << "Please enter your email: ";
	cin >> email;

	    //customer id
	cout << "Please enter your id: "; // 
	cin >> CustomerID;
	    
	   //set customer information
	customerOne.SetCustomerName(name);
	customerOne.SetCustomerEmail(email);
	customerOne.SetCustomerID(CustomerID);


	cout << endl;

	string line; // used in copying products file contents
	ifstream file;
	file.open("products.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream iss(line);

			if (iss >> id >> name >> price >> quantity) // parsing data
			{
				product[i].SetProductID(id);
				product[i].SetProductName(name);
				product[i].SetPrice(price);
				product[i].setQuantityInStock(quantity);
				i++;
			}
		}
	}

	file.close();
	int option = 0, continuechoice = 0, choice = 0; 
	

	cout << "Please enter 1 to continue or 0 to exit: ";
	cin >> continuechoice;

	while (cin.fail() || continuechoice < 0 || continuechoice > 1)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Please chooose again" << endl;
		cin >> continuechoice;
	}

	while (continuechoice == 1)
	{

		cout << endl << endl;

		// Print general menu
		PrintMenuOptions();

		cout << "Please select an option from the menu" << endl;
		cin >> option;

		while (cin.fail() || option < 1 || option > 8 || option == 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input. Please chooose again" << endl;
			cin >> option;
		}

		//used in the switch case statement
		string name;
		int quantity = 0; 
		int id = 0;
		int range = 0;

		switch (option)
		{
		case 1: // prints all items
			
			DisplayAvailableStock(product);
			cout << endl;

			cout << "Enter product id to add to cart: ";
			cin >> id;
			while (cin.fail() || id < 1 || id > 20 )
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> id;


			}

			cout << "Please enter the quantity: ";
			cin >> quantity;

			while (cin.fail() || quantity < 1) 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> id;
			}

			CheckQuantity(id, quantity);

			break;

		case 2: // searching by id
			
			cout << "Enter id: ";
			cin >> id;
			while (cin.fail() || id < 1 || id > 20 || id == 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> id;


			}

			SearchUsingProductID(id, product);

			cout << "Do you want to add this product to cart? 1-yes, 0- no ";
			cin >> choice;

			while (cin.fail() || choice > 1 || choice < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> choice;
			}

			cout << "Please enter the quantity: ";
			cin >> quantity;

			while (cin.fail() || quantity < 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> quantity;

				
			}

			CheckQuantity(id, quantity);

			break;




		case 3: //searching by price range

			PrintPriceRangeMenu();

			cout << "Please enter your choice of price range from the menu: ";
			cin >> range;

			while (cin.fail() || range < 1 || range > 4 || range == 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> range;
			}

			cout << endl;
			
			SearchUsingRange(range, product);

			cout << "Enter id of product :";
			cin >> id;
			while (cin.fail() || id < 1 || id > 20)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> id;
			}

			cout << "Please enter the quantity: ";
			cin >> quantity;

			while (cin.fail() || quantity < 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> quantity;
			}

			CheckQuantity(id, quantity);
			break;

		case 4: // print products in ascending order

			cout << "Printing products in ascending price" << endl;
			SortByAscendingPrice(product, MAX_PRODUCTS);

			cout << "Enter product id you wish to add to cart: ";
			cin >> id;

			while (cin.fail() || id < 1 || id > 20)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> id;


			}

			cout << "Please enter the quantity: ";
			cin >> quantity;

			while (cin.fail() || quantity < 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input. Please chooose again" << endl;
				cin >> quantity;
			}

			CheckQuantity(id, quantity);
			break;

		case 5: do {
			//system("CLS"); 
			PrintShoppingCartMenu();

			cout << "Please select an item from the menu OR enter -1 to exit: ";
			cin >> choice;

			switch (choice) {
			case 1:
				//system("CLS");
				cout << "Below are all the items in your cart" << endl << endl;
				cart.DisplayCartItems();
				
				break;

			case 2:
				//system("CLS");
				cart.DisplayCartItems();

				int id, quantity;

				cout << "Enter id of product you wish to remove: ";
				cin >> id;
				while (cin.fail() || id < 1 || id > 20) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input. Please choose again" << endl;
					cin >> id;
				}

				cout << "Enter the quantity that you want to remove: ";
				cin >> quantity;

				while (cin.fail() || quantity < 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input. Please choose again" << endl;
					cin >> quantity;
				}

				cart.RemoveItemFromCartWithProductID(id, quantity);
				
				break;

			case 3: // NEED TO ADD STUFF
				//system("CLS");
				
				break;

			case 0:
				cout << "Exiting the program. Goodbye!" << endl;
				break;

			default:
				cout << "Invalid choice. Please choose again." << endl;
			}

			//// Pause before clearing the screen again
			//cout << "Press Enter to continue...";
			//cin.ignore();
			//cin.get();

		} while (choice != -1);
			 

		case 6: //exits program
			cout << "Thank you for shopping with us." << endl;
			exit(0);


		default:
			cout << "Invalid option. Please choose a valid option from the menu." << endl;
		}



		cout << "Enter 1 to continue, 0 to exit "; // allow for continuation of program
		cin >> continuechoice;

		while (cin.fail() || continuechoice < 1 || continuechoice == 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input. Please chooose again" << endl;
			cin >> continuechoice;
		}

		system("CLS");
	}

	if (continuechoice == 0)
	{
		cout << "Thank you";
	}

	return 0;
}

// END OF MAIN FUNCTION

void DisplayAvailableStock(Product products[])  //change function name
{

	for (int i = 0; i < MAX_PRODUCTS; i++)
	{

		cout << "Product " << i + 1 << ": " << products[i].GetProductName() << ", Price: " << products[i].GetPrice() << endl;
	}
}

void DisplayOutOfStockProducts(Product products[])
{
	for (int i = 0; i < MAX_PRODUCTS; i++)
	{
		if (products[i].GetQuantityInStock() == 0)
		{
			products[i].DisplayBasicInfo();
		}
	}
}
void SearchUsingRange(int range, Product products[])
{

	if (range == 1)
	{

		for (int i = 1; i <= MAX_PRODUCTS; i++)
		{

			if (products[i].GetPrice() > 1 && products[i].GetPrice() < 300)
			{
				cout << "Product meets price range condition" << endl;
				products[i].DisplayBasicInfo();
				cout << endl;
			}
		}
	}

	else if (range == 2)
	{

		for (int i = 1; i <= MAX_PRODUCTS; i++)
		{

			if (products[i].GetPrice() > 300 && products[i].GetPrice() <= 600)
			{
				cout << "Product meets price range condition" << endl;
				products[i].DisplayBasicInfo();
				cout << endl;
			}
		}
	}

	else if (range == 3)
	{
		for (int i = 1; i <= MAX_PRODUCTS; i++)
		{

			if (products[i].GetPrice() > 600 && products[i].GetPrice() <= 900)
			{
				cout << "Product meets price range condition" << endl;
				products[i].DisplayBasicInfo();
				cout << endl;
			}
		}
	}

	else if (range == 4)
	{
		for (int i = 1; i <= MAX_PRODUCTS; i++)
		{

			if (products[i].GetPrice() > 900 && products[i].GetPrice() < 1200)
			{
				cout << "Product meets price range condition" << endl;
				products[i].DisplayBasicInfo();
				cout << endl;
			}
		}
	}
}

void SearchUsingProductName(string name, Product products[])
{
	for (char& c : name)
	{
		c = tolower(c);
	}

	for (int i = 0; i < MAX_PRODUCTS; i++)
	{
		if (products[i].GetProductName() == name)
		{
			products[i].DisplayBasicInfo();
			cout << endl;
		}
	}
}

void SearchUsingProductID(int id, Product products[])
{
	for (int i = 0; i < MAX_PRODUCTS; i++)
	{
		if (products[i].GetProductID() == id)
		{
			products[i].DisplayBasicInfo();
			cout << endl;
		}
	}
}

bool compareByPrice(Product& a, Product& b)
{
	return a.GetPrice() < b.GetPrice();
}

void SortByAscendingPrice(Product* product, int size)
{

	sort(product, product + size, compareByPrice);

	for (int i = 0; i < size; i++)
	{

		product[i].DisplayBasicInfo();
		cout << endl;
	}
}

// function to print menu
void PrintMenuOptions()
{
	cout << "Menu Options:" << endl;
	cout << "1. Print all products" << endl;
	cout << "2. Search by product ID" << endl;
	cout << "3. Search by price range" << endl;
	cout << "4. Sort products in ascending order of price" << endl;
	cout << "5. Display shopping cart" << endl;
	cout << "6. Exit" << endl;
}

// function to print price range
void PrintPriceRangeMenu()
{

	cout << "Price Range\t|\tOption" << endl;
	cout << "-------------------------------" << endl;
	cout << "$10 - $300\t|\t1" << endl;
	cout << "-------------------------------" << endl;
	cout << "$300 - $600\t|\t2" << endl;
	cout << "-------------------------------" << endl;
	cout << "$600 - $900\t|\t3" << endl;
	cout << "-------------------------------" << endl;
	cout << "$900 - $1200\t|\t4" << endl;
	cout << "-------------------------------" << endl;
}

void PrintShoppingCartMenu()
{
    cout << "\tMenu" << endl;
	cout << "You can select the numbers associatied with the items" << endl<<endl;
	cout << " 1. View all items from cart" << endl;
	cout << "-------------------------------" << endl;
	cout << " 2. Remove an item from the cart" << endl;
	cout << "-------------------------------" << endl;
	cout << " 3. Proceed to checkout" << endl;
	cout << "-------------------------------" << endl;
}

// input validations for name

bool IsNameValid(string name)
{
	return !name.empty() && all_of(name.begin(), name.end(), [](char ch)
		{ return isalpha(ch); });
}




void CheckQuantity(int quantity, int id) {
	if (product[id].GetQuantityInStock() >= quantity) {
		cart.AddItemToCart(product, MAX_PRODUCTS,quantity, id);
	}
	else {
		cout << "Quantity not in stock" << endl;
	}
}


