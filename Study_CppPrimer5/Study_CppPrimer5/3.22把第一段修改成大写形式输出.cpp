#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<string> vs;
	string s;
	if (getline(cin, s)){
		cout << "�������ݣ�" << s << endl;
		vs.push_back(s);
	}
	cout << "�ȴ����..." << endl;
	// ������vs����ַ���������vector������
	for (auto it = vs.begin(); it != vs.end() && !it->empty(); ++it){
		for (auto it2 = it->begin(); it2 != it->end(); ++it2){
			*it2 = toupper(*it2);
		}
		cout << *it << endl;
	}
	system("pause");
	return 0;
}