#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Time Complexity : Big O(log n) , Space Complexity : Big O(1)
int binarySearch(vector<int> vec, int key) {
	sort(vec.begin(),vec.end());
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (vec[mid] == key)
			return mid;
		else if (vec[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int> test = {4,7,9,8,5,3,2,0,-1,17,18,19,12,14,15,10};
	cout << "Please Enter an element to search for\n";
	int num; cin >> num;
	int res = binarySearch(test,num);
	if (res != -1)
		cout << "Element " << num << " is found at index " << res<<endl;
	else
		cout << "Element " << num << " is NOT found\n";
}