#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : Big O(n) , Space complexity : Big O(1)
int sequentialSearch(vector<int>vec,int key) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	vector<int> test = {4,5,7,9};
	cout << "Enter an element to search for\n";
	int num; cin >> num;
	int res = sequentialSearch(test, num);
	if (res != -1)
		cout << "Element " << num <<" is found at index "<< res <<endl;
	else 
		cout << "Element " << num << " is NOT found\n";
}