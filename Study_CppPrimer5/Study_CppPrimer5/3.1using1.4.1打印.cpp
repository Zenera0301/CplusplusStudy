#include<iostream>
using std::cout;
using std::endl;
using std::cin;

//打印，从大到小
void printNumberSmaller(int bigN, int smallN){
	while (bigN >= smallN){
		cout << bigN << endl;
		bigN--;
	}
}

//打印，从小到大
void printNumberBigger(int smallN, int bigN){
	while (bigN >= smallN){
		cout << smallN << endl;
		smallN++;
	}
}
//输入两个数字，打印两数之间的数，整数
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