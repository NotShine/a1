# include <iostream>

#include "Order.h"
#include "Customer.h"
#include "Shoppingcart.h"

using namespace std;


void Order::SetOrderID() {
	orderID = lastAssignedID++;
	}

	void Order::SetCustomer(Customer customer) {
		customer = customer;
	}

	void Order::SetProducts(Product product[], int count) {
		ProductCount = count;
		for (int i = 0; i < ProductCount; i++) {
			products[i] = product[i];
		}
	}

	void Order::SetTotalAmountToPay(double amount) {
		TotalAmountToPay = amount;
	}

	int Order::GetOrderID() {
		return orderID;
	}

	Customer Order::GetCustomer() {
		return customer;
	}

	Product* Order::GetProducts() {
		return products;
	}

	int Order::GetProductCount() {
		return ProductCount;
	}

	double Order::GetTotalAmount() {
		return TotalAmountToPay;
	}

	void Order::DisplayBasicInfo() {
		cout << "Order ID: " << orderID << endl;
		cout << "Customer ID: " << customer.GetCustomerID() << endl;
		cout << "Customer Name: " << customer.GetCustomerName() << endl;
		cout << "Customer Email: " << customer.GetCustomerEmail() << endl;
		cout << "Total Amount: " << TotalAmountToPay << endl;
		cout << "Products: " << endl;
		for (int i = 0; i < ProductCount; i++) {
			products[i].DisplayBasicInfo();
		}
	}

