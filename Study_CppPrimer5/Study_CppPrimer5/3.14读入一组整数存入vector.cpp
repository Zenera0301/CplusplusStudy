#include <iostream>
#include<vector>
using namespace std;

int main(){
	int num;
	vector<int> v;
	char cont = 'y';
	cout << "please input some numbers:" << endl;
	while (cin >> num){
		v.push_back(num);
		cout << "continue?" << endl;
		cin >> cont;
		if (cont != 'y'&&cont != 'Y'){

			break;
		}
	}
	for (auto p : v){
		cout << p<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}