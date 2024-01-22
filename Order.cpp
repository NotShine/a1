# include <iostream>

#include "Order.h"
#include "Customer.h"
#include "Shoppingcart.h"

using namespace std;


	

	void Order::SetOrderID(int id) {
		this->orderID = id;

	}

	void Order::SetCustomer(Customer cust) {
		customer = cust;
	}

	void Order::SetProducts(Product prods[], int count) {
		ProductCount = count;
		for (int i = 0; i < ProductCount; i++) {
			products[i] = prods[i];
		}
	}

	void Order::SetTotalAmount(double amount) {
		TotalAmount = amount;
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
		return TotalAmount;
	}

	void Order::DisplayBasicInfo() {
		cout << "Order ID: " << orderID << endl;
		cout << "Customer ID: " << customer.GetCustomerID() << endl;
		cout << "Customer Name: " << customer.GetCustomerName() << endl;
		cout << "Customer Email: " << customer.GetCustomerEmail() << endl;
		cout << "Total Amount: " << TotalAmount << endl;
		cout << "Products: " << endl;
		for (int i = 0; i < ProductCount; i++) {
			products[i].DisplayBasicInfo();
		}
	}
