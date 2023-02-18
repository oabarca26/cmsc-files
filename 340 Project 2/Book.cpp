#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "Book.h"
using namespace std;

Book::Book()
{
	bookName = "none";
	bookPrice = 0;
	bookAuthor = "none";
	bookQuantity = 0;
}

Book::Book(string name, string author, double price, int quantity)
{
	bookName = name;
	bookPrice = price;
	bookAuthor = author;
	bookQuantity = quantity;
}

void Book::SetName(string name)
{
	bookName = name;
}
void Book::SetPrice(double price)
{
	bookPrice = price;
}
void Book::SetAuthor(string author)
{
	bookAuthor = author;
}
void Book::SetQuantity(int quantity)
{
	bookQuantity = quantity;
}

string Book::GetName() const
{
	return bookName;
}
double Book::GetPrice() const
{
	return bookPrice;
}
string Book::GetAuthor() const
{
	return bookAuthor;
}
int Book::GetQuantity() const
{
	return bookQuantity;
}

string Book::PrintBookCost()
{
	stringstream myStringStream, myStringStream2;
	myStringStream2 << fixed << setprecision(2) << bookPrice;
	double totalCost = bookQuantity * bookPrice;
	myStringStream << fixed << setprecision(2) << totalCost;
	string myString2 = myStringStream2.str();
	string myString = myStringStream.str();
	return bookName + " " + to_string(bookQuantity) + " @ $" +  myString2 + " = $" + myString;
}

string Book::PrintBookDetails()
{
	return bookName + " by " + bookAuthor;
}