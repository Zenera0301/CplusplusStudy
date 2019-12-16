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

	decltype(v1.size()) size = v6.size();
	cout << "v1 µÄ´óÐ¡£º"<< size << endl;
	if (size > 0){
		for (auto i : v6){
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}