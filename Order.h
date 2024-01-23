#pragma once

#include "Customer.h"
#include "Product.h"

const int MAX = 20; // maximum products is 20

class Order :public Customer {
private:
    int orderID = 0;
    Customer customer;
    Product products[MAX];
    int ProductCount = 0;
    double TotalAmountToPay = 0;
    int lastAssignedID = 1;

public:
   // Order();
   // Order(int id, Customer cust, Product prods[], int count, double amount);

    void SetOrderID();
    void SetCustomer(Customer customer);
    void SetProducts(Product product[], int count);
    void SetTotalAmountToPay(double amount);

    int GetOrderID();
    Customer GetCustomer();
    Product* GetProducts();
    int GetProductCount();
    double GetTotalAmount();

    void DisplayBasicInfo();
 };
