#include<iostream>
#include<vector>
using namespace std;
int main(){
	int num;
	vector<int> vi;
	while (cin >> num){
		vi.push_back(num);
	}

	if (vi.cbegin() == vi.cend()){
		cout << "no numbers!" << endl;
		return -1;
	}

	for (auto i : vi){
		cout << i << " ";
	}
	cout << endl;

	/*
	//输出相邻数的和
	for (auto it = vi.begin(); it != vi.end()-1; it+=2){
		cout << *it + *(it + 1) << endl;
	}
	if (vi.size() % 2){
		cout << *(vi.end()-1) << endl;
	}*/
	//输出收尾和
	auto mid = vi.begin() + ((vi.end()-vi.begin()) / 2);
	for (auto it = vi.begin(); it != mid; it++){
		cout << *it + *(vi.begin() + (vi.end() - it - 1)) << endl;
	}
	if (vi.size() % 2){
		cout << *mid << endl;
	}
	
	system("pause");
	return 0;
}