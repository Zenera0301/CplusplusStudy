#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };

	//decltype(v2.size()) n = v2.size();

	cout << "ÔªËØ¸öÊý£º" << v2.size() << endl;
	if (v2.cbegin() != v2.cend()){
		for (auto it = v2.cbegin(); it != v2.cend(); ++it){//&& !it->empty()
			cout << *it << endl;
		}
	}
	




	system("pause");
	return 0;
}