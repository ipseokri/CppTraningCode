#include <iostream>
using namespace std;

int add (int a, int b){
    return a + b;
}

double add ( double a, double b){
    return a + b;
}

string add ( string a, string b){
    return a + b;
}



int main(void)
{
   int i1 = 10, i2 = 30;
   double d1 = 0.5, d2 = 3.5;
   string s1 = "Hello", s2 = "World";

   cout << add (i1, i2) << ", "
        << add (d1, d2) << ", "
        << add (s1, s2) << endl;

}