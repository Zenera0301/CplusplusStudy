#include <iostream>
using std::cout;
using std::endl;

int main(){
	int i = 50;
	int sum = 0;
	while (i <= 100){
		sum += i;
		i++;
	}
	cout << "����ǣ�" << sum << endl;
	system("pause");
	return 0;
}