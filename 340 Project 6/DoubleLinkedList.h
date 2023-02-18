#pragma once
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(const T& d, Node* n, Node* p) : data(d), next(n), prev(p) { }
	};
	Node* head;

public:
	DoubleLinkedList() : head(NULL) { }
	~DoubleLinkedList() {/*Implement if needed*/ 
		while (head != NULL) {
			Node* newNode = head->next;
			delete head;
			head = newNode;
		}
	}
	void push_front(const T& value) {
		/*Implement*/
		Node* newNode = new Node(value, head, NULL);
		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
	}

	friend std::ostream& operator<< (std::ostream& os, DoubleLinkedList<T>& linkedList)
	{
		for (Iterator iter = linkedList.begin(); iter != linkedList.end(); ++iter)
		{
			os << *iter << " ";
		}
		return os;
	}

	class Iterator
	{
	private:
		Node* iNode;
	public:
		Iterator(Node* head) : iNode(head) { }
		~Iterator() {/*Implement if needed*/ }

		//check if iNode is the same
		bool operator!=(const Iterator& rhs) const
		{
			//Implement
			return iNode != rhs.iNode;
		}

		//prefix increment

		Iterator& operator++()
		{
			//Implement
			iNode = iNode->next;
			return *this;
		}

		//prefix decrement
		Iterator& operator--()
		{
			//Implement
			iNode = iNode->prev;
			return *this;
		}

		//reference operator, return the data contained in iNode
		T& operator*() const
		{
			//Implement - then get rid of following statement
			return iNode->data;
		}

		//insert a new node with this value before this iterator
		//return an iterator to the new node
		Iterator& insert_before(const T& value) {
			//Implement
			Node* newNode = new Node(value, iNode, iNode->prev);
			if (iNode == NULL) {
				iNode = newNode;
				return *this;
			}
			iNode->prev->next = newNode;
			iNode->prev = newNode;
			return *this;
		}

		//insert a new node with this value after this iterator
		//return an iterator to the new node
		Iterator& insert_after(const T& value) {
			//Implement
			Node* newNode = new Node(value, nullptr, nullptr);
			if (iNode == NULL) {
				iNode = newNode;
				return *this;
			}
			newNode->prev = iNode;
			newNode->next = iNode->next;
			iNode->next = newNode; 
			iNode = newNode;
			return *this;
		}

		//remove the node this iterator is pointing to
		//return an iterator to the node after the removed node
		Iterator& remove() {
			//Implement
			Node* current = iNode;
			current->next->prev = current->prev;
			current->prev->next = current->next;

			delete current;
			current = NULL;
			return *this;
		}
	};

	/** Return iterator pointing to the first value in linked list */
	Iterator begin(void)
	{
		return DoubleLinkedList<T>::Iterator(head);
	}

	/** Return iterator pointing to something not in the linked list
	Returns an iterator referring to the past-the-end element in the
	list container. */
	Iterator end(void)
	{
		return DoubleLinkedList<T>::Iterator(NULL);
	}

	/*Returns an iterator to the first element in the range [first,last)
	that compares equal to value. The range searched is [first,last),
	which contains all the elements between first and last, including
	the element pointed by first but not the element pointed by last.
	If no elements match, the function returns end().*/
	Iterator find(Iterator first, Iterator last, const T& value)
	{
		//Implement then delete following line
		last = this->end();
		for (first = this->begin(); first != last; ++first)
		{
			if (value == *first)
			{
				return first;
			}
		}
		return end();
	}

	/*The container is extended by inserting a new element before the
	element at the specified position. The function returns an iterator
	pointing to the newly inserted element.
	If not found return end()
	
			iNode->prev->next = newNode;
			iNode->prev = newNode;*/
	Iterator insert_before(Iterator position, const T& value)
	{
		//Implement then delete following line
		Iterator last = this->end();
		for (Iterator first = this->begin(); first != last; ++first)
		{
			if (position != NULL)
			{
				position.insert_before(value);
				return DoubleLinkedList<T>::Iterator(position);
			}
		}
		return end();
	}

	/*The container is extended by inserting a new element after the
	element at the specified position. The function returns an iterator
	pointing to the newly inserted element.*/
	Iterator insert_after(Iterator position, const T& value)
	{
		//Implement then delete following line
		Iterator last = this->end();
		for (Iterator first = this->begin(); first != last; ++first)
		{
			if (position != NULL)
			{
				position.insert_after(value);
				return DoubleLinkedList<T>::Iterator(position);
			}
		}
		return NULL;
	}

	/** Return iterator pointing to next item after deleted node linked list */
	/*Removes from the list container a single element (position) and returns an
	iterator pointing to the element that followed the element erased by the function
	call. This is the container end if the operation erased the last element in the sequence.*/

	Iterator remove(Iterator position)
	{
		//Implement and delete following line
		Iterator last = this->end();
		for (Iterator first = this->begin(); first != last; ++first)
		{
			if (position != NULL)
			{
				position.remove();
				return DoubleLinkedList<T>::Iterator(position);
			}
		}
		return NULL;
	}

	/** Return a string from iterator position to beginning of linked list in reverse order,
	separated by a space*/
	string reverseString(Iterator position)
	{
		//Implement
		ostringstream oSS;
		position = end();
		while (position != nullptr) {
			oSS << *position << " ";
			++position;
		}
		return oSS.str();
	}

	//Assigns new_value to all the elements in the range [first,last) are equal to old_value. 
	void replace(Iterator first, Iterator last, const T& old_value, const T& new_value)
	{
		//Implement
		last = this->end();
		for (first = this->begin(); first != last; ++first)
		{
			if (old_value == *first)
			{
				*first = new_value;
			}
		}
	}

	//Returns all elements of the DoubleLinkedList separated by a space
	string toString() {
		ostringstream oSS;
		Iterator current = begin();
		while (current != end()) {
			oSS << *current << " ";
			++current;
		}
		return oSS.str();
	}
};
#pragma once
