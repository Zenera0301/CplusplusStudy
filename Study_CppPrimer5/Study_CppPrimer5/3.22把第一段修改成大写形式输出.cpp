#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<string> vs;
	string s;
	if (getline(cin, s)){
		cout << "输入内容：" << s << endl;
		vs.push_back(s);
	}
	cout << "等待输出..." << endl;
	// 遍历了vs这个字符串向量（vector容器）
	for (auto it = vs.begin(); it != vs.end() && !it->empty(); ++it){
		for (auto it2 = it->begin(); it2 != it->end(); ++it2){
			*it2 = toupper(*it2);
		}
		cout << *it << endl;
	}
	system("pause");
	return 0;
}