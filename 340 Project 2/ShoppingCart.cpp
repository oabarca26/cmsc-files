#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2021";
    vector<Book> cartItems;
}
ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	currentDate = date;
    vector<Book> cartItems;
}

string ShoppingCart::GetCustomerName() const {
	return customerName;
}
string ShoppingCart::GetDate() const {
	return currentDate;
}

void ShoppingCart::AddItem(Book item) {
	cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(string name) {
    unsigned int i;
    for (i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == name) {
            cartItems.erase(cartItems.begin() + i);
        }
    }
    if(cartItems.size() == 0) {
    cout << "Item not found in cart. Nothing removed." << endl;
        }
}

void ShoppingCart::ModifyQuantity(string bookName, int quantity) {
   unsigned int i;
    for (i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == bookName) {
            cartItems.at(i).SetQuantity(quantity);
        }
        else {
            cout << "Item not found in cart. Nothing modified." << endl;
        }
    }
}

int ShoppingCart::GetNumItemsInCart() {
    unsigned int i;                    
    int quant = 0;
    for (i = 0; i < cartItems.size(); i++) {
        quant  += cartItems.at(i).GetQuantity();
    }
    return quant;
}
double ShoppingCart::GetCostOfCart() {
    unsigned int i;
    double totalSum = 0.00;
    for (i = 0; i < cartItems.size(); i++) {
        totalSum = totalSum + cartItems.at(i).GetPrice();
    }
    return totalSum;
}

string ShoppingCart::PrintTotal() {
    unsigned int i;
    stringstream myStringStream, myStringStream2, myStringStream3, myStringStream4;
    double total = 0.00;
    myStringStream2 << "OUTPUT SHOPPING CART" << endl << customerName << "\'s Shopping Cart - " << currentDate << endl;
    if (cartItems.size() == 0) {
        myStringStream << "Number of Items: " << GetNumItemsInCart() << endl;
        myStringStream4 << endl << "SHOPPING CART IS EMPTY" << endl;
        string myString4 = myStringStream4.str();
        myStringStream << myString4;
        myStringStream3 << endl << "Total: $" << fixed << setprecision(2) << total;
        string myString3 = myStringStream3.str();
        myStringStream << myString3;
    }
    else {
        myStringStream << "Number of Items: " << GetNumItemsInCart() << endl << endl;
        for (i = 0; i < cartItems.size(); i++) {
            myStringStream << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" <<
                cartItems.at(i).GetPrice() << " = $" << cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity() << endl;
            total += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
        }
        myStringStream << endl << "Total: $" << total;
    }
    string myString = myStringStream.str();
    string myString2 = myStringStream2.str();
    return myString2 + myString;
}
string ShoppingCart::PrintDescriptions() {
    unsigned int i;
    stringstream myStringStream, myStringStream2;
    string myString;
    myStringStream2 << "OUTPUT ITEMS' DESCRIPTIONS" << endl << customerName << "\'s Shopping Cart - " << currentDate << endl;
    if (cartItems.size() == 0) {
        myStringStream << "SHOPPING CART IS EMPTY" << endl;
        myString = myStringStream.str();
    }
    else {
        myStringStream << endl << "Item Descriptions" << endl;
        for (i = 0; i < cartItems.size(); i++) {
            if(i == cartItems.size()-1)
            myStringStream << cartItems.at(i).GetName() << " by " << cartItems.at(i).GetAuthor();
            else
                myStringStream << cartItems.at(i).GetName() << " by " << cartItems.at(i).GetAuthor() << endl;
        }
        myString = myStringStream.str();
    }
    string myString2 = myStringStream2.str();
    return myString2 + myString;
}

