#include <iostream>
using namespace std;
template <class T>
class LinkedList {
	struct Node
	{
		T item;
		Node* next;
	};
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList() {
		head = tail = NULL;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	void insertFirst(T item) {
		Node* newNode = new Node;
		newNode->item = item;
		if (isEmpty()) {
			head = tail = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void size() {
		cout << length << endl;
	}
	void getFirst() {
		if (isEmpty())
			cout << "NULL\n";
		else
			cout << head->item << endl;
	}
	void getLast() {
		if (isEmpty())
			cout << "NULL\n";
		else
			cout << tail->item << endl;
	}
	void insert(T item) {
		Node* newNode = new Node;
		newNode->item = item;
		if (isEmpty()) {
			head = tail = newNode;
			newNode->next = NULL;
		}
		else {
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		length++;
	}
	void insertAtPos(int pos, int item) {
		if (pos > length || pos < 0)
			cout << "Out Of Range\n";
		else {
			Node* newNode = new Node;
			newNode->item = item;
			if (pos == 0)
				insertFirst(item);
			else if (pos == length)
				insert(item);
			else {
				Node* curr = head;
				for (int i = 1; i < pos; i++)
					curr = curr->next;
				newNode->next = curr->next;
				curr->next = newNode;
			}
			length++;
		}
	}
	void print() {
		Node* curr = head;
		cout << "{ ";
		while (curr != NULL) {
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << "}\n";
	}
	void deleteFirst() {
		Node* curr;
		if (isEmpty())
			cout << "List Is Already Empty!\n";
		else if (length == 1) {
			delete head;
			head = tail = NULL;
			length--;
		}
		else {
			curr = head;
			head = head->next;
			delete curr;
			length--;
		}
	}
	void deleteLast() {
		Node* curr;
		if (isEmpty()) 
			cout << "List Is Already Empty!\n";
		else if (length == 1) {
			delete head;
			tail = head = NULL;
			length--;
		}
		else {
			curr = head->next;
			Node* prev;
			prev = head;
			while (curr != tail) {
				prev = curr;
				curr = curr->next;
			}
			tail = prev;
			delete curr;
			prev->next = NULL;
			length--;
		}
	}
	void deleteAtPos(int pos) {
		if (isEmpty())
			cout << "List Is Already Empty!\n";
		else if (pos == 0)
			deleteFirst();
		else if (pos == length - 1)
			deleteLast();
		else if (pos < 0 || pos >= length)
			cout << "Out Of Range!\n";
		else {
			Node* curr=head->next;
			Node* prev=head;
			for (int i = 1;i<pos;i++) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = curr->next;
			delete curr;
			length--;
		}
	}
	void deleteByValue(T item) {
		if (isEmpty())
			cout << "List Is Already Empty!\n";
		else if (item == head->item)
			deleteFirst();
		/*else if (item == tail->item)
			deleteLast();*/ //if repeated value in middle and end will delete end first not by order
		else {
			Node* curr = head->next;
			Node* prev = head;
			while (curr != NULL){
				if (curr->item == item)
					break;
				prev = curr;
				curr = curr->next;
			}
			if (curr == NULL)
				cout << "Element Not Found!\n";
			else if (curr == tail) 
				deleteLast();
			else {
				prev->next = curr->next;
				delete curr;
				length--;
			}	
		}
	}
	void reverse() {
		if (isEmpty())
			cout << "Cant Revers Empty List!\n";
		else {
			Node* curr = head;
			Node* prev = NULL;
			Node* next = head->next;
			tail = curr;
			while (next != NULL) {
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
	}
	int search(T item) {
		Node* curr = head;
		int pos = 0;
		while (curr != NULL) {
			if (curr->item == item) {
				//cout << "Element Is Found At Index " << pos << endl;
				return pos;
			}
			curr = curr->next;
			pos++;
		}
		if (curr == NULL)
			return -1; //cout << "Element Not Found!\n";
	}
};
int main()
{
	LinkedList <int> l;
	l.insertFirst(4);
	l.insertFirst(5);
	l.insert(7);
	//l.insertAtPos(4, 3);
	l.insertAtPos(2, 3);
	/*l.deleteFirst();
	l.deleteLast();
	l.deleteAtPos(4);*/
	l.insert(4);
	l.deleteByValue(4);
	/*l.deleteByValue(4);
	l.deleteByValue(4);
	l.deleteFirst();*/
	l.reverse();
	cout<<l.search(4)<<endl;
	cout << "list = "; l.print();
	cout << "first = "; l.getFirst();
	cout << "last = "; l.getLast();
	cout << "size = "; l.size();
}