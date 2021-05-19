#include <iostream>

using namespace std;

class A{
public:
    int temp_A;
    A():temp_A(0){ cout << "Constructor in class A executed" << endl; } ;
    ~A() { cout << "Destructor in class A executed" << endl; };
};

class B : public A{
public:
    int temp_B;
    B():temp_B(0){ cout << "Constructor in class B executed"<< endl;} ;  
    ~B() { cout << "Destructor in class B executed" << endl; };
};

class C : public B{
public:
    int temp_C;
    C():temp_C(0){ cout << "Constructor in class C executed" << endl;} ;
    ~C() { cout << "Destructor in class C executed" << endl; };
};

int main()
{
    C* pc = new C;
    delete pc; 
}