#include <iostream>
#include <string>
using namespace std;
class A{
	int a;
   public:
	virtual void func() = 0;
};
 
class B: public A{
   public:
	void func(){
		cout << "Awesome" << endl;
	}	
};
 
int main(){
	A a;
	a.func();
	return 0;
}