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

void DisplayAvailableStock(Product products[]);

void SearchUsingRange(int range, Product product[]);

void SearchUsingProductID(int id, Product products[]);

void SortByAscendingPrice(Product* product, int size);

void PrintPriceRangeMenu();

void PrintMenuOptions();

void PrintShoppingCartMenu();

bool IsNameValid(string name);



//void EnterValidProductId();



Product products[MAX_PRODUCTS]; // create an array of objects

int main()
{

    int id, i = 0, quantity = 0;
    double price = 0;
    string name, email;

    Customer customerOne;
    ShoppingCart cart;
    cout << "Welcome to Treasure Traders" << endl << endl;

    do
    {
        cout << "Enter your name: ";
        getline(cin, name);

        // Validate the input
        if (!IsNameValid(name))
        {
            cout << "Invalid input. Please enter a valid name." << endl;
        }
    } while (!IsNameValid(name));
    cout << "Please enter your email: ";
    cin >> email;

    customerOne.SetCustomerName(name);
    customerOne.SetCustomerEmail(email);


    cout << endl;

    string line;

    ifstream file;
    file.open("products.txt");

    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream iss(line);

            if (iss >> id >> name >> price >> quantity)
            {
                products[i].SetProductID(id);
                products[i].SetProductName(name);
                products[i].SetPrice(price);
                products[i].setQuantityInStock(quantity);
                i++;
            }
        }
    }

    file.close();
    int option = 0, continuechoice = 0;
    int choice = 0; // i think i can reuse this.
    ;

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

        string name;
        int quantity = 0; // num products(same) that is added
        int id = 0;
        int range = 0;

        switch (option)
        {
        case 1:
            // prints all items
            DisplayAvailableStock(products);
            cout << endl;

            cout << "Enter product id to add to cart: "; // NEED TO ADD VALIDATE FUNCTION HERE
            cin >> id;
            while (cin.fail() || id < 1 || id > 20 || id == 0)
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



            break;

        case 2:
            // searching by id
            cout << "Enter id: ";
            cin >> id;
            while (cin.fail() || id < 1 || id > 20 || id == 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input. Please chooose again" << endl;
                cin >> id;
            }

            SearchUsingProductID(id, products);

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



            break;




        case 3:

            // function to print price range
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
            //function to search w range
            SearchUsingRange(range, products);

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
                cin >> id;
            }
            break;

        case 5:

            cout << "Printing products in ascending price" << endl;
            SortByAscendingPrice(products, MAX_PRODUCTS);

            cout << "Enter product id: ";
            cin >> id;

            while (cin.fail() || id < 1 || id > 20)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input. Please chooose again" << endl;
                cin >> id;
            }
            break;

        case 6: // display shopping cart

            PrintShoppingCartMenu();

            cout << "Please select an item from the menu: ";
            cin >> choice;

            if (choice == 1)
            {

                cout << "Below are all the items in your cart" << endl;
                cart.DisplayCartItems(); // this does not work, prolly enters function but doesnt go through loop
            }

            else if (choice == 2)  //HAVE TO CHECK THIS
            {

                do
                {
                    cout << "Enter the name of product to remove from cart: ";
                    getline(cin, name);

                    // Validate the input
                    if (!IsNameValid(name))
                    {
                        cout << "Invalid input. Please enter a valid name." << endl;
                    }
                } while (!IsNameValid(name));

                cart.RemoveItemFromCartWithProductName(name); // can have an option to remove from either name or id
            }

            else if (choice == 3)
            {

                Order orderOne;

                cout << "Order for :" << orderOne.GetCustomerName() << endl;
                cout << "Customer ID: " << orderOne.GetCustomerID() << endl;
                cout << "Customer Email: " << orderOne.GetCustomerEmail() << endl;

                cout << "Below is your final selection of items in cart" << endl;

                orderOne.cart.DisplayCartItems(); // this doesnt work, i think.
            }

        case 7: // exit program

        default:
            cout << "Invalid option. Please choose a valid option from the menu." << endl;
        }

        // END OF SWITCH STATEMENT

        cart.AddItemToCart(id, quantity);



        cout << "Enter 1 to continue, 0 to exit ";
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

void DisplayAvailableStock(Product products[])
{

    for (int i = 0; i < MAX_PRODUCTS; i++)
    {

        cout << "Product " << i + 1 << ": " << products[i].GetProductName() << " - Quantity: " << products[i].GetQuantityInStock() << ", Price: " << products[i].GetPrice() << endl;
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

    sort(products, products + size, compareByPrice);

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
    // cout << "Menu Item\t|\tOption" << endl;
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

// Function to get a valid product ID
void EnterValidProductId() {
    int id = 0;
    cout << "Enter the ID of the product to add to cart:  1, 20" << endl;
    cin >> id;
}