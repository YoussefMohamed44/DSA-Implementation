#include <iostream>
using namespace std;
class arrayList {
	int* arr;
	int maxsize;
	int length;
public:
	arrayList(int size) {
		if (size <= 0)
			maxsize = 100;
		else
			maxsize = size;
		length = 0;
		arr = new int[maxsize];
	}
	bool isEmpty() {
		return length == 0;
	}
	bool isFull() {
		return length == maxsize;
	}
	void getSize() {
		cout << length<<endl;
	}
	void print() {
		if (isEmpty())
			cout << "array is empty" << endl;
		else {
			cout << "{ ";
			for (int i = 0;i<length;i++) {
				cout << arr[i]<<" ";
			}
			cout << "}"<<endl;
		}	
	}
	void insertAt(int index,int element) {
		if (isFull())
			cout << "array is full" << endl;
		else if (index<0 || index>length)
			cout << "out of range" << endl;
		else if (index == length) {
			arr[index] = element;
			length++;
		}
		else {
			for (int i = length;i > index;i--) {
				arr[i] = arr[i-1];
			}
			arr[index] = element;
			length++;
		}		
	}
	void removeAt(int index) {
		if (isEmpty())
			cout << "array is empty" << endl;
		else if (index<0 || index>=length)
			cout << "out of range" << endl;
		else {
			for (int i = index;i < length;i++) {
				arr[i] = arr[i + 1];
			}
			length--;
		}
	}
	int search(int element) {
		if (isEmpty())
			cout << "array is empty" << endl;
		else {
			for (int i = 0;i < length;i++) {
				if (arr[i] == element)
					return i;
			}
			return -1;
		}
	}
	void insertWithoutDuplicate(int element) {
		if (isFull())
			cout << "array is full" << endl;
		else if (search(element) == -1) {
			arr[length] = element;
			length++;
		}
		else
			cout << "element exist" << endl;
	}
	void updateAt(int index,int element) {
		if (index < 0 || index >= length)
			cout << "out of range" << endl;
		else
			arr[index] = element;
	}
	void getELement(int index) {
		if (index < 0 || index >= length)
			cout << "out of range" << endl;
		else
			cout << arr[index]<<endl;
	}

};
int main()
{
	arrayList arr(5);
	arr.insertAt(0,1);
	arr.insertAt(1, 2);
	arr.insertAt(2, 3);
	arr.insertAt(3, 4);
	arr.insertWithoutDuplicate(5);
	//cout <<arr.search(4)<<endl;
	//arr.getELement(3);
	//arr.updateAt(4,7);
	arr.removeAt(0);
	arr.print();
	arr.getSize();
}
