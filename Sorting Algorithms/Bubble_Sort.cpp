#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : Big O (n²) , Space Complexity : Big O (1)
// ַבװֽׁ : ָהדװם הÞַׁה ַָב ַב 2 ַםבדםהÊ זהָֿב ַבַßָׁ בֽֿ ד םזױב ַ־ׁ ַהֿםß׃ זוß׀ַ
void BubbleSort(vector<int> vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		bool sorted = true; // ßב בÝֹ וÝÊׁײ ַה ַבַַׁם ַÊׁÊָÊ ־בַױ
		for (int j = 0; j < vec.size() - i - 1; j++) {
			// (size-i-1) -> Úװַה ßב דֹׁ והßזה ׁÊָהַ ַ־ׁ Úהױׁ זױבהַבו זוהÞÝ Úהֿ ַבבם Þָבו
			if (vec.at(j) > vec.at(j + 1)) { // בז Úַםׂ ÊׁÊםָ Êהַׂבם והÚß׃ ַבÚבַדֹ ָ׃
				swap(vec.at(j),vec.at(j+1));
				sorted=false; // בז Úדב ׃זַָ םָÞם ב׃ו דÊׁÊָÊװ
			}
		}
		//בז Ýײב Êׁז םÚהם דֽױבװ ׃זַָ Ý ַבבÝֹ ֿם Ý ום״בÚ דה ַבבזָ ־בַױ דה Ûםׁ דַ םßדב
		if (sorted == true) //זֿם ַבדםֹׂ Úה ַב׃םבםßװה ׃זׁÊ ַבבם וםײ״ׁ םßדב בבַ־ׁ
			break;
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << " ";
	}
}
int main()
{
	vector<int> v = {4,3,1,5,2,9,7,14,18};
	BubbleSort(v);
}
