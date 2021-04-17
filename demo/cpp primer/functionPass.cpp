#include <iostream>
#include <initializer_list>

using namespace std;

// 1.建议使用引用类型的形参替代指针，避免拷贝， 
void swap1(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;	
}

void swap2(int &num1, int &num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// 2.如果函数无须修改引用形参的值，最好将其声明为常量引用 
// 3.使用引用形参可以返回额外的信息，函数需要多个返回值时 
// 例如链表中删除元素的时候，可以用引用类型返回删除的对象，函数的返回值返回删除操作是否正确执行。 
// 4.初始化的过程，会忽略顶层的const。 fun(const int value):传入常量或者不是常量均可

// 5.printNum函数的形参都是const int* num类型的，所以printNum(&i,1)也可以调用这个函数; 
// 6.显式的传递一个表示数组长度的形参 
void printNum(const int num[], const int length){
	for(int i = 0; i < length; i++)
		cout << num[i] << endl;
} 

// 可变长度 
void print(initializer_list<int> il){
	for(auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << endl;
} 

// 省略符形参 foo(...) 

// 函数的返回值不能是局部变量的引用，因为函数执行完，局部变量的空间被回收，返回值指向不可再用的空间；指针也是一样
// 返回引用的函数可以作为左值，其他类型的做右值

// 使用尾置返回类型 auto fun(int i) -> int(*) [10] 同 int (*fun(int i)) [10] 

int main(){
	int i = 2, j = 3;
	int* pi = &i;
	int *pj = &j;
	swap1(pi,pj);
	cout << i <<endl;
	cout << j <<endl;
	
	swap2(i,j);
	cout << i <<endl;
	cout << j <<endl;
	
	int num[3] = {2,4,5};
	printNum(num,3);
	printNum(&i,1);
	
	print({1,2,3});
	
	return 0;
}
