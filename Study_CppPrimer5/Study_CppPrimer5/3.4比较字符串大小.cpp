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
		cout << "�������" << endl;
	}*/

	if (str1.size() > str2.size()){
		cout << str1 << endl;
	}
	else if (str1.size() < str2.size()){
		cout << str2 << endl;
	}
	else{
		cout << "���ߵȳ�" << endl;
	}
	system("pause");
	return 0;
}