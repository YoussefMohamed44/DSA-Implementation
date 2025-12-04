#include <iostream>
using namespace std;
template <class t>
class stack {
	struct node {
		t item;
		node* next;
	};
	node* top;
public:
	stack() {
		top = NULL;
	}
	void push(t element) {
		node* newelement = new node;
		newelement->item = element;
		newelement->next = top;
		top = newelement;
	}
	bool isEmpty() {
		return top == NULL;
	}
	void pop() {
		if (isEmpty())
			cout << "stack is empty";
		else {
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void pop(t& stack_top) {
		if (isEmpty())
			cout << "stack is empty";
		else {
			stack_top = top->item;
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void get_top(t& stack_top) {
		if (isEmpty())
			cout << "stack is empty";
		else {
			stack_top = top->item;
			cout << stack_top<<endl;
		}
	}
	void print() {
		node* display = top;
		cout << "{ ";
		while (display != NULL) {
			cout << display->item << " ";
			display = display->next;
		}
		cout << "}" << endl;
	}
};
int main() {
	stack<int>s;
	s.push(5);
	s.push(15);
	s.push(25);
	s.push(50);
	s.push(10);
	int x;
	s.print();
	s.get_top(x);
}