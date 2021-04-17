#include <iostream>

using namespace std;

void print(){
	cout << "�����һ��packageΪ�յ�ʱ����õĺ���" << endl;
}
template <typename T, typename... Types> 
void print(const T& firstArg, const Types&... args){
	cout << firstArg << endl;
	print(args...);
	cout << sizeof...(args) << endl;// ����ģ������ĸ����� 
}



int main(){
	std::cout << __cplusplus << std::endl; // 201103
	print(7.5,"hello",377, 42);
	double x = 5.0;
	double &rx = x;
	cout << sizeof(rx) << endl;
	cout << sizeof(x) << endl; 
	cout << &x << endl;// 0x6ffe00
	cout << &rx << endl;// 0x6ffe00
}
