#include <iostream>

#include <vector>

using std::vector;

int main(){
	// vector��һ����ģ�壬�������͡� 
	// ʵ����
	// ͨ���ṩԪ�ص�������ָ��ģ�嵽��ʵ����ʲô������
	// ���ò��Ƕ��󣬲��������õ�vector
	
	// ����ͳ�ʼ��
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3 = v1;
	vector<int> v4(10, 1);
	vector<int> v5(10);
	vector<int> v6{1,2,4};
	vector<int> v7 = {1,2,4};
	
	// �б��ʼ����Ԫ������ 
	vector<int> v8(10,1);// ʮ��Ԫ�أ���Ϊһ 
	vector<int> v9{10,1};// ����Ԫ�أ�һ��1һ��10
	
	// ������{}��С����()
	// �������ڵ�������ģ��һ����Ϊ�б��ʼ������Ϊint������С����һ��
	vector<string> v10{10};
	vector<string> v11{10, "hi"}; 
	 
	// ʹ��push_back���Ԫ��,����ʹ���±����Ԫ�أ�ֻ�ܶ��Ѿ����ڵ��±���в��� 
	v1.push_back(10);
	// �ж��Ƿ�Ϊ�� 
	std::cout << v1.empty() << std::endl;
	// vector�Ĵ�С
	std::cout << v1.size() << std::endl;
	
}
