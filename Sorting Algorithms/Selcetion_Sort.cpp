#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : Big O (n≤) , Space Complexity Big O (1)
// «б‘—Ќ : яб г—… »дбЁ Џбн »«ён «б«—«н ябе« дЌѕѕ «’џ— Џд’— ждЌЎе Ён «б«дѕня” «ббн Џбне «бѕж—	
void selectionSort(vector<int> vec) { 
	int minIndex;
	for (int i = 0; i < vec.size() - 1; i++) {
		minIndex = i;
		int j = i + 1;
		for (; j < vec.size(); j++) {
			if (vec.at(j) < vec.at(minIndex))
				minIndex = j;
		}
		swap(vec.at(i),vec.at(minIndex));
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << " ";
	}
}
int main()
{
	vector<int> v = {10,-1,0,1,5,6,20,4,19,9,7,17,15,12,14};
	selectionSort(v);
}