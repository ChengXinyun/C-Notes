#include <iostream>

#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	//string��ʼ�� 
	string s1;//Ĭ�ϳ�ʼ�������ַ���
	string s2 = "cxy";//������ʼ�� 
	string s3 = s2;
	string s4(s2);//ֱ�ӳ�ʼ�� 
	string s5("cxy");
	string s6(10, 'c');
	cout << s6 <<endl;//cccccccccc
	 
	string line;
	while(getline(cin, line)){//���԰�ctrl+z���� 
		// ����getline���ص��Ǹ����з��������ˣ��õ���line�в��������з� 
		if(!line.empty() && line.size() > 10) 
			cout << line << endl;
	} 
	
	// size()�������ص���һ��string::size_type���͵�ֵ
	// �޷��������� 
	cout << (s4.size() < -1) << endl;// cout: 1 
	cout << (int(s4.size()) < -1) << endl;// cout: 0
	
	 
	return 0;
}
