#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;

template <class Type_t> 
Stack<Type_t>::Stack() {
	Count = 0;
	top = NULL;
	cout << "Constructor OK\n";
}

template <class Type_t> 
Type_t* Stack<Type_t>::Top() {
	try {
		if(!Count) throw "Stack is empty";
        return (top->inf);
	}
	catch(char* err) {
		cout << "\nReading failed: " << err << "! Continuing...\n";
        return (top->inf);
	}
	
}

template <class Type_t> 
int Stack<Type_t>::Push(Type_t *Data) {
	try {
        Node<Type_t> *newElement = new Node<Type_t>(Data);
		if (!Count) {
			newElement->prev = NULL;
			top = newElement;
		}
		else {
			newElement->prev = top;
			top = newElement;
		}
		Count++;
		return 0;
	}
	catch(bad_alloc err) {
		cout << "\nAllocating memory failed. Critical!\n";
		exit(1);
	}
}

template <class Type_t> 
int Stack<Type_t>::Pop() {
	try {
		if (!Count) throw "Nothing in stack";
		if (Count > 1) {
            Node<Type_t> *Del = top;
			top = top->prev;
			delete Del;
		}
		else {
			delete top;
			top = NULL;
		}
		Count--;
		return 0;
	}
	catch(char* err) {
		cout << "\nCan not POP: " << err << ". Continuing...\n";
		return 1;
	}
}

template <class Type_t>
int Stack<Type_t>::GetCount() {
    return Count;
}

template <class Type_t> 
Stack<Type_t>::~Stack() {
     while(Count) Pop();
}

template <class Type_t> 
Stack<Type_t>::Iterator::Iterator() {
	element = NULL;
}

template <class Type_t> 
Stack<Type_t>::Iterator::Iterator(Node<Type_t> *elementIn) {
	element = elementIn;
}

template <class Type_t> 
typename Stack<Type_t>::Iterator Stack<Type_t>::Iterator::operator=(Node<Type_t> *elementRight) {
	element = elementRight;
	return *this;
}

template <class Type_t> 
typename Stack<Type_t>::Iterator Stack<Type_t>::Iterator::operator--() {
	element = element->prev;
	return *this;
}

template <class Type_t> 
typename Stack<Type_t>::Iterator Stack<Type_t>::Iterator::operator--(int) {
	Iterator temp(*this);
	element = element->prev;
	return temp;
}

template <class Type_t> 
Type_t Stack<Type_t>::Iterator::operator*() {
	return *element->inf;
}

//template <class Type_t>
//bool operator!=(const typename Stack<Type_t>::Iterator &l, const typename Stack<Type_t>::Iterator &r) {
//	return l.element != r.element;
//}
