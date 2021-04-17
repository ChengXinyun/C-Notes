#include <iostream>

#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	//string初始化 
	string s1;//默认初始化，空字符串
	string s2 = "cxy";//拷贝初始化 
	string s3 = s2;
	string s4(s2);//直接初始化 
	string s5("cxy");
	string s6(10, 'c');
	cout << s6 <<endl;//cccccccccc
	 
	string line;
	while(getline(cin, line)){//可以按ctrl+z结束 
		// 触发getline返回的那个换行符被丢弃了，得到的line中不包括换行符 
		if(!line.empty() && line.size() > 10) 
			cout << line << endl;
	} 
	
	// size()函数返回的是一个string::size_type类型的值
	// 无符号整型数 
	cout << (s4.size() < -1) << endl;// cout: 1 
	cout << (int(s4.size()) < -1) << endl;// cout: 0
	
	 
	return 0;
}
