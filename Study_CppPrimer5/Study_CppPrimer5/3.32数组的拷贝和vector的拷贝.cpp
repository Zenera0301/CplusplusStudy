#include<iostream>
#include<vector>
using namespace std;

int main(){
	//สýื้
	//const int sz = 10;
	//int a[sz], b[sz];
	//for (int i = 0; i < sz; ++i){
	//	a[i] = i;
	//}
	//for (int i = 0; i < sz; ++i){
	//	b[i] = a[i];
	//}
	//for (auto i : b){
	//	cout << i << " ";
	//}
	//cout << endl;

	//vector
	const int sz = 10;
	vector<int> c, d;
	for (int i = 0; i < sz; i++){
		c.push_back(i);
	}
	for (int i = 0; i < sz; i++){
		d.push_back(c[i]);
	}
	for (auto i : d){
		cout << i << " ";
	}
	cout << endl;


	

	system("pause");
	return 0;
}