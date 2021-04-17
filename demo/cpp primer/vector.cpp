#include <iostream>

#include <vector>

using std::vector;

int main(){
	// vector是一个类模板，而非类型。 
	// 实例化
	// 通过提供元素的类型来指定模板到底实例化什么样的类
	// 引用不是对象，不存在引用的vector
	
	// 定义和初始化
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3 = v1;
	vector<int> v4(10, 1);
	vector<int> v5(10);
	vector<int> v6{1,2,4};
	vector<int> v7 = {1,2,4};
	
	// 列表初始化和元素数量 
	vector<int> v8(10,1);// 十个元素，均为一 
	vector<int> v9{10,1};// 两个元素，一个1一个10
	
	// 花括号{}和小括号()
	// 花括号内的类型与模板一致则为列表初始化，若为int，则与小括号一致
	vector<string> v10{10};
	vector<string> v11{10, "hi"}; 
	 
	// 使用push_back添加元素,而不使用下标添加元素，只能对已经存在的下标进行操作 
	v1.push_back(10);
	// 判断是否为空 
	std::cout << v1.empty() << std::endl;
	// vector的大小
	std::cout << v1.size() << std::endl;
	
}
