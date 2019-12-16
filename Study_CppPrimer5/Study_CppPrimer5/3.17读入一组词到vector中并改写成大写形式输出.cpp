#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string word;
	vector<string> vs;
	char cont = 'y';
	cout << "please input a word:" ;
	while (cin >> word){
		vs.push_back(word);
		cout << "continue?" << endl;
		cin >> cont;
		if (cont != 'y' && cont != 'Y'){
			break;
		}

	}
	for (auto &mem : vs){
		for (auto &c : mem){
			c = toupper(c);
		}
		cout << mem << endl;
	}

	system("pause");
	return 0;
}