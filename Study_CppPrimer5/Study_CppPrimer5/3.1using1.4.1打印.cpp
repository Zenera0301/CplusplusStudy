#include<iostream>
using std::cout;
using std::endl;
using std::cin;

//��ӡ���Ӵ�С
void printNumberSmaller(int bigN, int smallN){
	while (bigN >= smallN){
		cout << bigN << endl;
		bigN--;
	}
}

//��ӡ����С����
void printNumberBigger(int smallN, int bigN){
	while (bigN >= smallN){
		cout << smallN << endl;
		smallN++;
	}
}
//�����������֣���ӡ����֮�����������
void putinNumber(){
	int firstN = 0, secondN = 0;
	cout << "Please input two numbers:" << endl;
	cin >> firstN >> secondN;
	if (firstN < secondN){
		printNumberBigger(firstN, secondN);
	}
	else if (firstN == secondN){
		cout << firstN << endl;
	}
	else{
		printNumberSmaller(firstN, secondN);
	}
}
int main(){
	//printNumberSmaller(10, 0);

	putinNumber();
	system("pause");
	return 0;
}