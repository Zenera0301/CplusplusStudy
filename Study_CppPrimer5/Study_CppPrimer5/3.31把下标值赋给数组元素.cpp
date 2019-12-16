#include<iostream>
using namespace std;

int main(){
	const int array_size = 10;
	int ia[array_size];
	for (int i = 0; i < array_size; i++){
		ia[i] = i;
	}

	for (auto i : ia){
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}