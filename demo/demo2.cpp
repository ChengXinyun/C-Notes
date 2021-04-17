#include <iostream>

using namespace std;

class A{
	public:
		virtual void mi(){
		}
};

class B: public A{

};

int main(){
	A ss;
	B bb;
	cout << sizeof(ss) << endl;
	return 0;
}
