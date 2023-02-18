#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Book.h"

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string name, string date);

    string GetCustomerName() const;
    string GetDate() const;

    void AddItem(Book item);
    void RemoveItem(string name);

    void ModifyQuantity(string bookName, int quantity);

    int GetNumItemsInCart();
    double GetCostOfCart();

    string PrintTotal();
    string PrintDescriptions();

    char PrintMenu(ShoppingCart item);


private:
    string customerName;
    string currentDate;
    vector<Book> cartItems;
};
