#include <iostream>

using namespace std;

int main(){
	// initialize���Ǹ�ֵ����ʼ���ĺ������ڴ���������ʱ����һ����ʼֵ��
	// ����ֵ�ǰѶ���ĵ�ǰֵ����������һ����ֵ�������
	
	// �б��ʼ��
	int units_sold = 0;
	// int units_sold = {0}; //C++11�±�׼���û���������ʼ�������� 
	// int units_sold{0};
	// int units_sold(0);
	 
	long double ld = 3.1415926536;
	int a{ld}, b{ld}; // ��������������ת��δִ�У����ڶ�ʧ��Ϣ��Σ��
	int c(ld), d = ld; // ��ȷ��ת��ִ�У���ʧ������Ϣ 
	
	// Ĭ�ϳ�ʼ��
	int i;
	cout << i << endl; 
	 
	//extern:������һ���������������䲢�����ڶ������j����δΪj�����ڴ�ռ䡣
	extern int j;
	j = 10;
	cout << j << endl;
	return 0;
}
