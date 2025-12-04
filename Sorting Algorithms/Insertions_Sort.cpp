#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : Big O (n²) , Space Complexity : Big O (1)
// ÇáÔÑÍ : ãßÓá ÑæÍ Ôæİ İíÏíæ Úã ÚÇÏá ÇÓåá
// ãÚ ÇááíäßÏ áíÓÊ åíßæä ÇÍÓä ÚÔÇä ãÔ åÊÍÊÇÌ Çí áæÈ ááÓæÇÈ ÇäÓíÑÊ ÚáØæá İÇáÈæÒíÔä ÇáãØáæÈ
void insertionSort(vector<int> vec) {
	int key, j;
	for (int i = 1; i<vec.size();i++) {
		key = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j]>key) { // áæ ÚÇíÒ ÊÑÊíÈ ÊäÇÒáí ÇÚßÓ ÇáÇÔÇÑÉ 
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
	for (int i = 0; i < vec.size(); i++) 
		cout << vec[i] << " ";
}
int main()
{
	vector<int> v = {4,5,14,9,7,10,18,12,19,0,1,-1,3};
	insertionSort(v);
}