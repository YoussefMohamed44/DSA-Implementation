#include <iostream>
#include <vector>
using namespace std;
// Time complexity : Big O(n log n)
// Space complexity : Big O(n) => needs extra space one more time as the original 
// => with linked list it's Big O(1) no need to extra space (best use) 
void merge(vector<int> &vec, int start,int mid ,int end) { // mid = start + (end - start) / 2
	vector<int> left(mid-start+1);//left subarray [start => m]
	vector<int> right(end-mid);//right subarray [m+1 => end]

	for (int i = 0; i < left.size(); i++)
		left[i] = vec[start+i];
	for (int j = 0; j <right.size(); j++)
		right[j] = vec[mid+1+j];

	int i = 0, j = 0, k = start;
	while (i < left.size() && j < right.size()) { //storing the smallest first in the vector (sorting)
		if (left[i] <= right[j]) { // to make it descending order swap the operator here to (>=) 
			vec[k] = left[i];
			i++;
		}
		else {
			vec[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size()) { //if left size > right size store the remaining elements of left in the end
		vec[k] = left[i];
		i++;
		k++;
	}
	while (j < right.size()) { //if right size > left size store the remaining elements of right in the end
		vec[k] = right[j];
		j++;
		k++;
	}
}
// merge function time complexity = O(n)

void mergeSort(vector<int>&vec ,int start,int end) {
	if (start<end) { // dividing the original to single elements => every one as a subarray
		int mid = start + (end - start) / 2; // calculating the new mid every time
		mergeSort(vec,start,mid);
		// the left subarry [start => mid(last mid as its new end)] then recursion to get it divided again
		mergeSort(vec, mid + 1, end);
		// the right subarry [mid(last mid as its new start) => end] then recursion to get it divided again

		merge(vec,start,mid,end);
		//after that merging all of them agian to get it sorted
	}
}
// the dividing operation recursion will work like the tree (look at the screenshot in the file)
// so it take time O(log n) then the merging will take time O(n) thats so mergeSort takes O(n log n)

int main()
{
	int size;
	cin >> size;
	vector<int> vec(size);
	for (int i = 0; i < size; i++)
		cin >> vec[i];
	mergeSort(vec,0,vec.size() - 1);
	for (int i : vec) 
		cout << i << " ";
}