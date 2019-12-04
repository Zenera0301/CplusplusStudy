#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
int main(){
	//string line;
	//while (getline(cin, line)){
	//	cout << line << endl;
	//}
	
	string word;
	while (cin >> word){
		cout << word << endl;
	}
	return 0;
}