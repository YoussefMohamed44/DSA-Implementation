#include <iostream>
using namespace std;
template <class T>
class DoublyLinkedList {
    struct Node{
        T item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int length;
public:

    DoublyLinkedList() {
        first = last = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void size() {
        cout << "Size = " << length <<endl;
    }

    void getFirst() {
        if (isEmpty())
            cout << "First = " << "NULL\n";
        else
            cout << "First = " << first->item << endl;
    }

    void getLast() {
        if (isEmpty())
            cout << "Last = " << "NULL\n";
        else
            cout << "Last = " << last->item << endl;
    }

    void print() {
        Node* curr=first;
        cout << "List = { ";
        while (curr != NULL) {
            cout << curr->item<<" ";
            curr = curr->next;
        }
        cout << "}\n";
    }

    void insertFirst(T item) {
        Node* newNode = new Node;
        newNode->item = item;
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;  
        }
        length++;
    }

    void insert(T item) {
        Node* newNode = new Node;
        newNode->item = item;
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void insertAtPosition(T item,int pos) {
        if (pos<0 || pos>length)
            cout << "Out Of Range!\n";
        else if (pos == 0)
            insertFirst(item);
        else if (pos == length)
            insert(item);
        else {
            Node* newNode = new Node;
            newNode->item = item;
            Node* curr = first;
            for (int i = 1; i < pos; i++) {
                curr = curr->next;
            }   
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode;
            curr->next = newNode;
            length++;
        }
    }

    void deleteFirst() {
        if (length == 0)
            cout << "List Is Already Empty!\n";
        else if (length == 1) {
            delete first;
            first = last = NULL;
            length--;
        }
        else {
            Node* curr = first;
            first = first->next;
            first->prev = NULL;
            delete curr;
            length--;
        }
    }

    void deleteLast() {
        if (length == 0)
            cout << "List Is Already Empty!\n";
        else if (length == 1) {
            delete first;
            last = first = NULL;
            length--;
        }
        else {
            Node* curr=last;
            last = last->prev;
            last->next = NULL;
            delete curr;
            length--;
        }
    }

    void deleteAtPosition(int pos) {
        if (pos<0 || pos>=length)
            cout << "Out Of Range!\n";
        else if (pos == 0)
            deleteFirst();
        else if (pos == length-1)
            deleteLast();
        else {
            Node* curr = first;
            for (int i = 1; i <= pos; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            length--;
        }
    }

    void delteByValue(T item) {
        if (item == first->item)
            deleteFirst();
        else if (item == last->item)
            deleteLast();
        else {
            Node* curr=first;
            while (curr != NULL) {
                if (item == curr->item)
                    break;
                curr = curr->next;
            }
            if (curr == NULL)
                cout << "Element Not Found!\n";
            else if (curr->next == NULL)
                deleteLast();
            else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                length--;
            }
        }
    }

    void reverse() {
        Node* curr = last;
        cout << "List = { ";
        while (curr != NULL) {
            cout << curr->item << " ";
            curr = curr->prev;
        }
        cout << "}\n";
    }

    int searchIndex(T item) {
        Node* curr = first;
        int counter = 0;
        while (curr != NULL) {
            if (item == curr->item)
                return counter;
            curr = curr->next;
            counter++;
        }
        return -1;
    }

    void search(T item) {
        Node* curr = first;
        int counter = 0;
        while (curr != NULL) {
            if (item == curr->item) {
                cout << "Element Found In Index " << counter<<endl;
                return;
            }
            curr = curr->next;
            counter++;
        }
        cout<<"Element Not Found\n";
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;
        }
        last = NULL;
        length = 0;
    }
};

int main()
{
    DoublyLinkedList <int> l;
    l.insert(5); //4 5 3 7
    l.insertFirst(4);
    l.insert(7);
    l.insertAtPosition(3,2);
    //l.deleteFirst();
    //l.deleteFirst();
    //l.deleteLast();
    //l.deleteLast();
    //l.deleteAtPosition(3);
    //l.delteByValue(3);
    l.print();
    l.getFirst();
    l.getLast();
    l.size();
    l.reverse();
    cout << l.searchIndex(1)<<endl;
    l.search(1);
}