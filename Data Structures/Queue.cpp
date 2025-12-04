#include <iostream>
using namespace std;
template <class t>
class queue {
	struct node {
		t item;
		node* next;
	};
	node* front;
	node* rear;
	int length;
public:
	queue() {
		front = rear = NULL;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	void enqueue(t item) {
		node* new_item = new node;
		new_item->item = item;
		new_item->next = NULL;
		if (isEmpty())
			front = rear = new_item;
		else {
			rear->next = new_item;
			rear = new_item;
		}
		length++;
	}
	void dequeue() {
		if (isEmpty())
			cout << "queue is empty"<<endl;
		else if (length == 1) {
			front = rear = NULL;
			length = 0;
		}
		else {
			node* temp = front;
			front = front->next;
			temp->next = NULL;
			delete temp;
			length--;
		}
	}
	void get_front() {
		if (isEmpty())
			cout << "queue is empty" << endl;
		else
			cout << front->item<<endl;
	}
	void get_rear() {
		if (isEmpty())
			cout << "queue is empty" << endl;
		else
			cout << rear->item << endl;
	}
	void print() {
		if (isEmpty()) 
			cout << "queue is empty" << endl;
		else {
			node* display = front;
			cout << "{ ";
			while (display != NULL) {
				cout << display->item<<" ";
				display= display->next;
			}
			cout << "}"<<endl;
		}
	}
	void clear() {
		node* current;
		while (front != NULL) {
			current = front;
			front = front->next;
			current->next=NULL;
			delete current;
		}
		rear = NULL;
		length = 0;
	}
	void get_Size() {
		cout << length<<endl;
	}
	void search(t item) {
		if (isEmpty()) 
			cout << "queue is empty" << endl;
		else {
			node* current = front;
			bool flag = 1;
			while (current != NULL) {
				if(current->item==item){
					cout << "item is found" <<endl;
					flag = 0;
					break;
				}
				current = current->next;
			}
			if (flag)
				cout << "item not found" << endl;
		}
	}
};
int main()
{
	queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();
	//q.clear();
	q.print();
	cout << "front = ";q.get_front();
	cout << "rear = ";q.get_rear();
	cout << "size = ";q.get_Size();
	q.search(10);
}