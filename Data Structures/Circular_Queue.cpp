#include <iostream>
using namespace std;
template <class t>
class queue {
	int rear;
	int front;
	int count;
	t *arr;
	int max_size;
public:
	queue(){
		max_size = 100;
		arr = new t[max_size];
		front = 0;
		rear = max_size - 1;
		count = 0;
	}
	queue(t size) {
		if (size <= 0)
			max_size = 100;
		else
			max_size = size;
		arr =new t[max_size];
		front = 0;
		rear = max_size - 1;
		count = 0;
	}
	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == max_size;
	}
	void enqueue(t element) {
		if (isFull())
			cout << "queue is full"<<endl;
		else{
			rear = (rear + 1) % max_size;
			arr[rear] = element;
			count++;
		}
	}
	void dequeue() {
		if (isEmpty())
			cout << "queue is empty"<<endl;
		else {
			front = (front + 1) % max_size;
			count--;
		}
	}
	void dequeue(t& deleted_front) {
		if (isEmpty())
			cout << "queue is empty"<<endl;
		else {
			deleted_front = arr[front];
			front = (front + 1) % max_size;
			count--;
		}
	}
	void get_front() {
		if (isEmpty())
			cout << "queue is empty" << endl;
		else
		cout<< arr[front]<<endl;
	}
	void get_rear() {
		if (isEmpty())
			cout << "queue is empty" << endl;
		else
		cout<<arr[rear]<<endl;
	}
	void print() {
		if (isEmpty())
			cout << "queue is empty"<<endl;
		else{
			cout << "{ ";
			for (int i = front;i != rear;i = (i + 1) % max_size) {
				cout << arr[i]<<" ";
			}
			cout << arr[rear] << " }" << endl;
		}
	}
	void search(t element) {
		int pos = -1;
		if (!isEmpty()) {
			for (int i = front;i != rear;i = (i + 1) % max_size) {
				if (arr[i] == element) {
					pos = i;
					break;
				}
			}
			if (pos == -1&& arr[rear] == element) {
					pos = rear;
			}
		}
		else
			cout << "queue is empty"<<endl;
		if (pos == -1)
			cout << "element not found";
		else
			 cout<< pos << endl;
	}
};
int main() {
	queue<int>q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	int x = 0;
	q.dequeue(x);
	q.enqueue(x);
	q.enqueue(70);
	//q.dequeue();
	//q.dequeue();
	//q.dequeue();
	//q.dequeue();
	q.print();
	q.get_front();
	q.get_rear();
	q.search(70);
}