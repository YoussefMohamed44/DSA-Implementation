#include <iostream>
#include <vector>
using namespace std;

// Quick Sort
// Time Complexity : Big omega(n log n) ,Big theta(n log n)
// Space Complexity : Big O(1)
// Big O (n) Ïí ÇáãíÒÉ ÈÊÇÚÊå Úä ÇáãíÑÌ ÓæÑÊ Çááí ÈíÇÎÏ äİÓ ÇáÊÇíã ÈÓ ÇáÓÈÇíÓ  

// partition :
// ÈäãÔí ãä ÈÚÏ ÇáÇäÏíßÓ Çááí ÇÎÊÇÑäÇå ßÓÊÇÑÊ äÎáí ßá Çááí ŞÈáå ÇÕÛÑ ãäå
// æßá Çááí ÈÚÏå ÇßÈÑ ãäå
int partition(vector<int>&vec,int start,int end) {
	int pivot=vec[start];
	int i = start;
	int j = end;
	while (i < j) {
		do {
			i++; 
	//ÚÔÇä íÈÏÇ ãä Çááí ÈÚÏÇáÈíİæÊ İí Çæá áİÉ æíßãá ãä ÈÚÏ ÇÎÑ ŞíãÉ ÚáØæá İÇááİÇÊ Çááí ÈÚÏ ßÏå  
		} while (i < end && vec[i] <= pivot); // ÈíãÔí áÍÏ ã íáÇŞí Çæá ÚäÕÑ ÇßÈÑ ãäå
		do {
			j--;
	//ÚÔÇä íÈÏÇ ãä ÇÎÑ ÇäÏíßÓ İÇáÇÑÇí İí Çæá áİÉ æíßãá ãä ÈÚÏ ÇÎÑ ŞíãÉ ÚáØæá İÇááİÇÊ Çááí ÈÚÏ ßÏå
		} while (j > start && vec[j] > pivot);
		// ÈíãÔí áÍÏ ã íáÇŞí Çæá ÚäÕÑ ÇŞá ãäå ãä äÇÍíÉ ÇáÇÎÑ
		if (i < j) 
			swap(vec[i],vec[j]); //æíÚãáåã ÓæÇÈ ÈÚÏ ßÏå 
	}
	swap(vec[start],vec[j]);// íÚÏæÇ ãä ÈÚÖ åíßæä ØáÚ ãä ÇááæÈ i,j áãÇ 
							// j æíÚãá ÓæÇÈ ááÈíİæÊ ãÚ ÇÎÑ ÇäÏíßÓ æÕáå Çá
	return j;
}
void quickSort(vector<int>& vec, int start, int end) {
	if (start < end) {
		int pivotIndex = partition(vec, start, end); // äÌíÈ ÇäÏíßÓ ÇáÈíİæÊ ÈÚÏ Çæá ÈÇÑÊíÔä
		quickSort(vec, start, pivotIndex);
		// åäãÔí ãä ÚäÏå æäßÑÑ äİÓ ÇáÚãíáÉ Ú ÇááíİÊ ÓÇÈ ÇÑÇí ÈÊÇÚå áÍÏ ã íÊÈŞí ÇäÏíßÓ æÇÍÏ æåíßæä äÇÍíÉ ÇááíİÊ ßáåÇ ÇÊÑÊÈÊ ßÏå
		quickSort(vec, pivotIndex + 1, end);// ÈÚÏåÇ äİÓ ÇáÚãáíÉ Ú ÇáÑÇíÊ ÓÇÈ ÇÑÇí ÈÊÇÚ Çæá ÈíİæÊ 
	}
}
int main()
{
	vector<int> test = {4,9,7,5,14,8,12,10,17,19,3,1,0,-1,2};
	quickSort(test,0,test.size());
	for(int i : test)
		cout << i << " ";
	//1 2 3 4 5 6 7 (alreay sorted) is the worst case
	//starting with first index in this case will cause Big O(n²)
	//to solve it we can start form the middle or random index using rand method 
}