#include<iostream>
#include<string>
using namespace std;

int main(){
	string str1, str2;
	cin >> str1 >> str2;
	/*if (str1 > str2){
		cout << str1 << endl;
	}
	else if(str1<str2){
		cout << str2 << endl;
	}
	else{
		cout << "两者相等" << endl;
	}*/

	if (str1.size() > str2.size()){
		cout << str1 << endl;
	}
	else if (str1.size() < str2.size()){
		cout << str2 << endl;
	}
	else{
		cout << "两者等长" << endl;
	}
	system("pause");
	return 0;
}