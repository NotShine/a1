#pragma once

#include "Customer.h"
#include "Product.h"

class Order {
private:
    int orderID;
    Customer customer;
    Product products[10];
    int ProductCount;
    double TotalAmount;

public:
   // Order();
   // Order(int id, Customer cust, Product prods[], int count, double amount);

    void SetOrderID(int id);
    void SetCustomer(Customer cust);
    void SetProducts(Product prods[], int count);
    void SetTotalAmount(double amount);

    int GetOrderID();
    Customer GetCustomer();
    Product* GetProducts();
    int GetProductCount();
    double GetTotalAmount();

    void DisplayBasicInfo();
};
