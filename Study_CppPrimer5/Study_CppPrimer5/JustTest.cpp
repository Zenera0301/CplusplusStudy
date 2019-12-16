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


	//string s = "hello world.";
	//for (auto c : s){
	//	c = toupper(c);
	//}
	//cout << s << endl;


	/*string s("some thing");
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index){
		s[index] = toupper(s[index]);
	}
	cout << s << endl;*/

	//把0-15之间的十进制数转换成对应的十六进制形式
	const string hexdigits = "0123456789ABCDEF";
	string result;
	string::size_type n;
	while (cin >> n){
		if (n < hexdigits.size()){
			result += hexdigits[n];
		}
		cout << "Your hex number is: " << result << endl;
	}
	

	system("pause");
	return 0;
}