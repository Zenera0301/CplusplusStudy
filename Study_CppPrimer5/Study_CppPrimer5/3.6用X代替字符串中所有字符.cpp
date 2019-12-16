#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	
	//for (decltype(s.size()) num = 0; num < s.size(); ++num){
	//	s[num] = 'X';
	//}

	//decltype(s.size()) num = 0;
	//while (num < s.size()){
	//	s[num] = 'X';
	//	++num;
	//}


	for (char &c : s){
		c = 'X';
	}


	cout << s[0] << endl;

	system("pause");
	return 0;
}