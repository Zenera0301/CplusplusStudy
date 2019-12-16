#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> vInt;
	int iVal;
	cout << "please input some num:";
	while (cin >> iVal){
		vInt.push_back(iVal);
	}

	if (vInt.size() == 0){
		cout << "no numbers!" << endl;
		return -1;
	}


	cout << "相邻两数和是："; 
	for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i+=2){
		cout << vInt[i] + vInt[i + 1] << " ";
		if ((i + 2) % 10 == 0){
			cout << endl;
		}
	}
	if (vInt.size() % 2 != 0){
	cout << vInt[vInt.size() - 1];
	}
	system("pause");
	return 0;
}