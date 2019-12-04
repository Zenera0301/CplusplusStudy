#include<iostream>
#include<string>
using std::string;
using namespace std;
int main(){
	/*string a = "hello world~~~";
	string m = a + "m" + "n";
	decltype(a.size()) num = 0;
	for (auto c : a){
		if (ispunct(c)){
			++num;
		}
	}
	cout << num << endl;
	system("pause");
	return 0;*/


	string s = "hello world.";
	for (auto c : s){
		c = toupper(c);
	}
	cout << s << endl;
	system("pause");
	return 0;
}