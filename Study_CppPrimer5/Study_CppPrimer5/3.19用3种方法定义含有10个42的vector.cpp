#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v1(10, 42);//最最最省事
	
	vector<int> v2(10);
	for (auto &i : v2){
		i = 42;
	}


	vector<int> v3;
	for (int i = 0; i < 10; i++){
		v3.push_back(42);
	}


	for (auto i : v1){
		cout << i << " ";
	}
	cout << endl;
	for (auto i : v2){
		cout << i << " ";
	}
	cout << endl;
	for (auto i : v3){
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}