#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	multimap<string, string> authors;
	authors.insert({"abc","Book1"});
	authors.insert({"aaa","Book3"});
	authors.insert({"aaa","Book4"});
	authors.insert({"abc","Book2"});
	
	string item{"abc"};
	
	auto nums = authors.count(item);
	auto iter = authors.find(item); 
	while(nums){
		cout << iter->second << endl;
		++iter;
		--nums;
	}
	int arr[4] = {1,2,3,4};
	cout << &arr <<endl;         // 0x70fd90
	cout << &arr + 1 <<endl;     // 0x70fda0
	cout << &arr[0] + 1 << endl; // 0x70fd94
	return 0;
}
