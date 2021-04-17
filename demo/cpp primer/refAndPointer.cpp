#include <iostream>

using namespace std;

int main(){
	// 指针和引用 
	
	// 引用并非对象，它只是为一个已经存在的对象所起的另外一个名字
	int i = 1;
	int &ref = i;
	// int &ref2; // 报错：引用必须被初始化
	int j = 2;
	// &ref = j; // 报错：无法将ref绑定至j
	ref = j; // 相当于 i = j 
	cout << ref << endl; // 2 
	cout << i << endl; // 2 
	//int &refint = 1.01; // 报错： 引用类型的初始值必须是一个对象
	 
	// 指针也和引用一样，都实现了对其他对象的间接访问
	// 1. 指针本身是一个对象，允许赋值和拷贝操作，可以改变指向不同的对象
	// 2. 指针无须在定义的时候赋初始值，和其他的内置类型一样，如果没有赋值，会有一个不确定的值
	int val = 42;
	int *p = &val;
	*p = 0;
	cout << val << endl;
	
	p = 0; // 现在的p不指向任何对象了 ，是一个空指针 
	// cout << *p << endl; // 没有输出 
	 
	//以下语句等价 
	int *p1 = nullptr;
	int *p2 = 0;
	int *p3 = NULL; 
	
	cout << p1 << endl; // 0
	// cout << *p1 << endl; // 无输出
	
	// const 和 extern 
	// 如果想在多个文件之间共享const对象，必须加上extern关键字
	 
	return 0;
}
