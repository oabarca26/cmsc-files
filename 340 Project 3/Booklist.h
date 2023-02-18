#pragma once
#include "BooklistNode.h"


class Booklist {
private:
	BooklistNode* head;
	BooklistNode* tail;

public:
	Booklist();
	~Booklist();
	bool add(string name, string artist, int yearPublished);
	BooklistNode* found(string bookName);
	bool remove(string bookname);
	bool moveFront(string bookname);
	string displayAuthor(string authorName);
	int totalBooks();
	string displayList();
	BooklistNode* getHead();
	BooklistNode* getTail();
};