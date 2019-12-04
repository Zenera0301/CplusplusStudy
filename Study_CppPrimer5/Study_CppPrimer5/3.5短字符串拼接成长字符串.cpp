#include<iostream>
#include<string>
using namespace std;
int main(){
	char cont = 'y';
	string s, result;
	cout << "Please input the first str:" << endl;
	while (cin >> s){
		//判断是否是第一个字符串
		if (!result.size()){
			result += s;
		}
		else{
			result += " " + s;
		}
		
		//判断用户输入意愿
		cout << "是否继续？" << endl;
		cin >> cont;
		if (cont == 'y' || cont == 'Y'){
			cout << "请输入下一个字符串：" << endl;
		}
		else{
			break;
		}
	}

	//最后的展示
	cout << "拼接后的字符串是：" << result << endl;
	system("pause");
	return 0;
}