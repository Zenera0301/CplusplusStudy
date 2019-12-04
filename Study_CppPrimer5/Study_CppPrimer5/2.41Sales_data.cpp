#include<iostream>
#include<string>
using namespace std;

class Sales_data{
	//友元函数
	friend std::istream& operator >> (std::istream&, Sales_data&);
	friend std::ostream& operator << (std::ostream&, const Sales_data&);
	friend bool operator < (const Sales_data&, const Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
	//构造函数
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

//比较书籍编号是否相同
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.isbn() == rhs.isbn();
}

Sales_data operator + (const Sales_data&, const Sales_data&);

//比较两个书籍对象是否是同种书籍对象
inline bool operator == (const Sales_data& lhs, const Sales_data&rhs){
	return lhs.units_sold == rhs.units_sold &&
		lhs.sellingprice == rhs.sellingprice &&
		lhs.saleprice == rhs.saleprice &&
		lhs.isbn() == rhs.isbn();
}

//比较两个书籍对象是否不为同种书籍对象
inline bool operator != (const Sales_data &lhs, const Sales_data & rhs){
	return !(lhs == rhs);
}

//实现两个同种书籍对象的 +=操作符
Sales_data& Sales_data::operator += (const Sales_data& rhs){
	units_sold += rhs.units_sold;
	saleprice = (rhs.saleprice*rhs.units_sold + saleprice*units_sold) / (rhs.units_sold + units_sold);
	if (sellingprice != 0){
		discount = saleprice / sellingprice;
	}
	return *this;
}

//实现两个同种书籍对象的 +操作符
Sales_data operator + (const Sales_data&lhs, const Sales_data&rhs){
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}

//输入一个书籍对象的相关信息
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

//打印书籍对象
std::ostream& operator << (std::ostream& out, const Sales_data& s){
	out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " <<s.saleprice<<" "<< s.discount;
	return out;
}

int main(){
	Sales_data book;
	std::cout << "请输入销售记录：" << std::endl;
	if (std::cin >> book){
		std::cout << "ISBN、售出本数、原始价格、实售价格、折扣为：" << book << std::endl;
	}
	

	Sales_data trans1, trans2;
	std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
	std::cin >> trans1 >> trans2;
	if (compareIsbn(trans1, trans2)){
		std::cout << "汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为：" << trans1+trans2 << std::endl;
	}
	else{
		std::cout << "两条销售记录的ISBN不同：" << std::endl;
	}

	Sales_data total, trans;
	std::cout << "请输入几条ISBN相同的销售记录：" << std::endl;
	if (std::cin >> total){
		while (std::cin >> trans){
			if (compareIsbn(total, trans)){
				total = total + trans;
			}
			else{
				std::cout << "当前书籍ISBN不同" << std::endl;
				break;
			}
		}
		std::cout << "有效汇总信息：ISBN、售出本数、原始价格、实售价格、折扣为：" << total << std::endl;
	}
	else{
		std::cout << "没有数据" << std::endl;
		return -1;
	}

	int num = 1;
	std::cout << "请输入若干销售记录：" << std::endl;
	if (std::cin >> trans1){
		while (std::cin >> trans2){
			if (compareIsbn(trans1, trans2)){
				num++;
			}
			else{
				std::cout << trans1.isbn() << "共有" << num << "条记录" << std::endl;
				trans1 = trans2;
				num = 1;
			}
		}
	}
	else{
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	return 0;
}
