#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
	vector<int> vi;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++){
		vi.push_back(rand() % 1000);
	}

	cout << "������ɵ�10�������ǣ�" << endl;
	for (auto it = vi.cbegin(); it != vi.cend(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	cout << "����֮���10�����ǣ�" << endl;
	for (auto it = vi.begin(); it != vi.end(); ++it){
		*it *=  2;
		cout << (*it) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}