#include <iostream>
#include <algorithm>

using namespace std;

void print(std::initializer_list<int> vals){
	for(auto p = vals.begin(); p != vals.end(); ++p){
		std::cout << *p << std::endl;
	}
}

class P{
	public:
		P(int a, int b){
			cout << "P(int, int)£¬a = " << a << ", b = " << b << endl; 
		} 
		P(initializer_list<int> initlist){
			cout << "P(initializer_list<int>), values = ";
			for(auto i : initlist){
				cout << i << " ";
			}
			cout << endl;
		}
		
		explicit P(int a, int b, int c){
			cout << "explicit succeded." << endl;
		}
};


int main(){
	P p(3,5);
	P q{2,4};
	P r{1,2,3};
	P s = {1,2};
	
	P m = {1,2,3};

	
	print({12,3,4,4,5.0,6});
	
	cout << max({1,2,3,4}) << endl;	
}
