#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string word;
	vector<string> v;
	char cont = 'y';
	cout << "please input some string:";
	while (cin >> word){
		v.push_back(word);
		cout << "continue?" << endl;
		cin >> cont;
		if (cont != 'y'&&cont != 'Y'){
			break;
		}
	}
	for (auto p : v){
		cout << p << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}