#include <iostream>
#include <initializer_list>

using namespace std;

// 1.����ʹ���������͵��β����ָ�룬���⿽���� 
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

// 2.������������޸������βε�ֵ����ý�������Ϊ�������� 
// 3.ʹ�������βο��Է��ض������Ϣ��������Ҫ�������ֵʱ 
// ����������ɾ��Ԫ�ص�ʱ�򣬿������������ͷ���ɾ���Ķ��󣬺����ķ���ֵ����ɾ�������Ƿ���ȷִ�С� 
// 4.��ʼ���Ĺ��̣�����Զ����const�� fun(const int value):���볣�����߲��ǳ�������

// 5.printNum�������βζ���const int* num���͵ģ�����printNum(&i,1)Ҳ���Ե����������; 
// 6.��ʽ�Ĵ���һ����ʾ���鳤�ȵ��β� 
void printNum(const int num[], const int length){
	for(int i = 0; i < length; i++)
		cout << num[i] << endl;
} 

// �ɱ䳤�� 
void print(initializer_list<int> il){
	for(auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << endl;
} 

// ʡ�Է��β� foo(...) 

// �����ķ���ֵ�����Ǿֲ����������ã���Ϊ����ִ���꣬�ֲ������Ŀռ䱻���գ�����ֵָ�򲻿����õĿռ䣻ָ��Ҳ��һ��
// �������õĺ���������Ϊ��ֵ���������͵�����ֵ

// ʹ��β�÷������� auto fun(int i) -> int(*) [10] ͬ int (*fun(int i)) [10] 

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
