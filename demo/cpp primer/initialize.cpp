#include <iostream>

using namespace std;

int main(){
	// initialize不是赋值，初始化的含义是在创建变量的时候赋予一个初始值，
	// 而赋值是把对象的当前值擦除，而以一个新值来替代。
	
	// 列表初始化
	int units_sold = 0;
	// int units_sold = {0}; //C++11新标准，用花括号来初始化变量。 
	// int units_sold{0};
	// int units_sold(0);
	 
	long double ld = 3.1415926536;
	int a{ld}, b{ld}; // 编译器报错，错误：转换未执行，存在丢失信息的危险
	int c(ld), d = ld; // 正确：转换执行，丢失部分信息 
	
	// 默认初始化
	int i;
	cout << i << endl; 
	 
	//extern:仅仅是一个变量的声明，其并不是在定义变量j，并未为j分配内存空间。
	extern int j;
	j = 10;
	cout << j << endl;
	return 0;
}
