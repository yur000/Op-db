#ifndef _STACK_
#define _STACK_

template <class Type_t> 
struct Node {
		Type_t *inf;
		Node *prev;
        Node(Type_t *Init) { inf = Init; };
	};
template <class Type_t> 
class Stack {
	int Count;
	Node<Type_t> *top;
public:
	Stack();
	~Stack();
    Type_t* Top();
    int Push(Type_t*);
    int GetCount();
    int Pop();
	class Iterator {
	private:
		Node<Type_t> *element;
	public:
		Iterator();
		Iterator(Node<Type_t>*);
		Iterator operator=(Node<Type_t>*);
		Iterator operator--();
		Iterator operator--(int);
		Type_t operator*();
		friend bool operator!=(const Iterator &l, const Iterator &r) {
			return l.element != r.element;
		}
	};
};
#endif 
