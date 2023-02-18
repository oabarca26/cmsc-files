#pragma once


#include <string>
using namespace std;

class Book {

public:
    Book();
    Book(string name, string author, double price, int quantity);

    void SetName(string name);
    void SetPrice(double price);
    void SetAuthor(string author);
    void SetQuantity(int quantity);

    string GetName() const;
    double GetPrice() const;
    string GetAuthor() const;
    int GetQuantity() const;

    string PrintBookCost();
    string PrintBookDetails();
    

private:
    string bookName;
    double bookPrice;
    string bookAuthor;
    int bookQuantity;
};
