#include<iostream>
#include<string>
using namespace std;

class Sales_data{
	//��Ԫ����
	friend std::istream& operator >> (std::istream&, Sales_data&);
	friend std::ostream& operator << (std::ostream&, const Sales_data&);
	friend bool operator < (const Sales_data&, const Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
	//���캯��
public:
	Sales_data() = default;
	Sales_data(const std::string &book) :bookNo(book){}
	Sales_data(std::istream &is){ is >> *this; }
public:
	Sales_data& operator += (const Sales_data&);
	std::string isbn() const { return bookNo; }
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};

//�Ƚ��鼮����Ƿ���ͬ
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.isbn() == rhs.isbn();
}

Sales_data operator + (const Sales_data&, const Sales_data&);

//�Ƚ������鼮�����Ƿ���ͬ���鼮����
inline bool operator == (const Sales_data& lhs, const Sales_data&rhs){
	return lhs.units_sold == rhs.units_sold &&
		lhs.sellingprice == rhs.sellingprice &&
		lhs.saleprice == rhs.saleprice &&
		lhs.isbn() == rhs.isbn();
}

//�Ƚ������鼮�����Ƿ�Ϊͬ���鼮����
inline bool operator != (const Sales_data &lhs, const Sales_data & rhs){
	return !(lhs == rhs);
}

//ʵ������ͬ���鼮����� +=������
Sales_data& Sales_data::operator += (const Sales_data& rhs){
	units_sold += rhs.units_sold;
	saleprice = (rhs.saleprice*rhs.units_sold + saleprice*units_sold) / (rhs.units_sold + units_sold);
	if (sellingprice != 0){
		discount = saleprice / sellingprice;
	}
	return *this;
}

//ʵ������ͬ���鼮����� +������
Sales_data operator + (const Sales_data&lhs, const Sales_data&rhs){
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}

//����һ���鼮����������Ϣ
std::istream& operator >> (std::istream& in, Sales_data& s){
	in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (in && s.sellingprice != 0){
		s.discount = s.saleprice / s.sellingprice;
	}
	else{
		s = Sales_data();
	}
	return in;
}

//��ӡ�鼮����
std::ostream& operator << (std::ostream& out, const Sales_data& s){
	out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " <<s.saleprice<<" "<< s.discount;
	return out;
}

int main(){
	Sales_data book;
	std::cout << "���������ۼ�¼��" << std::endl;
	if (std::cin >> book){
		std::cout << "ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ��" << book << std::endl;
	}
	

	Sales_data trans1, trans2;
	std::cout << "����������ISBN��ͬ�����ۼ�¼��" << std::endl;
	std::cin >> trans1 >> trans2;
	if (compareIsbn(trans1, trans2)){
		std::cout << "������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ��" << trans1+trans2 << std::endl;
	}
	else{
		std::cout << "�������ۼ�¼��ISBN��ͬ��" << std::endl;
	}

	Sales_data total, trans;
	std::cout << "�����뼸��ISBN��ͬ�����ۼ�¼��" << std::endl;
	if (std::cin >> total){
		while (std::cin >> trans){
			if (compareIsbn(total, trans)){
				total = total + trans;
			}
			else{
				std::cout << "��ǰ�鼮ISBN��ͬ" << std::endl;
				break;
			}
		}
		std::cout << "��Ч������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ��" << total << std::endl;
	}
	else{
		std::cout << "û������" << std::endl;
		return -1;
	}

	int num = 1;
	std::cout << "�������������ۼ�¼��" << std::endl;
	if (std::cin >> trans1){
		while (std::cin >> trans2){
			if (compareIsbn(trans1, trans2)){
				num++;
			}
			else{
				std::cout << trans1.isbn() << "����" << num << "����¼" << std::endl;
				trans1 = trans2;
				num = 1;
			}
		}
	}
	else{
		std::cout << "û������" << std::endl;
		return -1;
	}
	return 0;
}
