#include<iostream>
#include<string>
using namespace std;
int main(){
	char cont = 'y';
	string s, result;
	cout << "Please input the first str:" << endl;
	while (cin >> s){
		//�ж��Ƿ��ǵ�һ���ַ���
		if (!result.size()){
			result += s;
		}
		else{
			result += " " + s;
		}
		
		//�ж��û�������Ը
		cout << "�Ƿ������" << endl;
		cin >> cont;
		if (cont == 'y' || cont == 'Y'){
			cout << "��������һ���ַ�����" << endl;
		}
		else{
			break;
		}
	}

	//����չʾ
	cout << "ƴ�Ӻ���ַ����ǣ�" << result << endl;
	system("pause");
	return 0;
}