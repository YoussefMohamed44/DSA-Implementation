#include <iostream>
#include <vector>
using namespace std;
// Time complexity : Big O(n log n) in all cases
// space complexity : Big O(1)
// explanation : GO SEE ADEL NASIM VEDIO EASIER 
void heapify(vector<int>&vec,int size, int i) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int max = i;
	if (left < size && vec[left] > vec[max])
		max = left;
	if (right < size && vec[right] > vec[max])
		max = right;
	if (max != i) {
		swap(vec[i], vec[max]);
		heapify(vec,size,max);
	}	
}

void buildHeap(vector<int>&vec,int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(vec,size,i);
}
	
void heapSort(vector<int>&vec,int size) {
	buildHeap(vec,size);
	for (int i = size - 1; i >= 0; i--) {
		swap(vec[0], vec[i]);
		heapify(vec,i,0);
	}
}

int main()
{
	vector<int> test = {9,4,7,8,5,3,1,-1,0,2,-3,10,18,12,19,17,15,14};
	heapSort(test,test.size());
	for (int i : test)
		cout << i << " ";
}