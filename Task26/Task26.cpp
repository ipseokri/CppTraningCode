#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Quad{
public:
    T val1;
    T val2;
    T val3;
    T val4;

    Quad(T input1, T input2, T input3, T input4):val1(input1), val2(input2), val3(input3), val4(input4) {};

    template <typename T2>
    friend ostream& operator << (ostream& , const Quad<T2> & ref);
};

template <typename T>
ostream& operator << (ostream& os, const Quad<T> & ref){
    os << "Elements are : <" << ref.val1 << ", " << ref.val2 << ", " << ref.val3 << ", " << ref.val4 << ">";
    return os;
}


int main ()
{

  Quad<int> qi (5,6,7,8);

  Quad<string> qs ("hello", "C++", "programming", "language");

  Quad<double> qd (1.1, 2.2, 3.3, 4.4);

 

  cout << qi << endl;

  cout << qs << endl;

  cout << qd << endl;

}

