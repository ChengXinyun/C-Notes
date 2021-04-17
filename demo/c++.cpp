#include <iostream>
using namespace std;

class Component{
	public:
		Component(){
			cout << "Component construct"<<endl;
		}
		~Component(){
			cout << "Component desconstruct"<<endl;
		}
};

class Base{
	public:
		Base(){
			cout << "Base construct"<<endl;
		}
		~Base(){
			cout << "Base desconstruct"<<endl;
		}
};

class Derived:public Base{
	public:
		Derived(){
			cout << "Derived construct"<<endl;
		}
		~Derived(){
			cout << "Derived desconstruct"<<endl;
		}
	private:
		Component component;
};

int main(){
	Derived a;
	return 0;
} 




