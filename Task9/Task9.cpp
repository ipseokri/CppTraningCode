#include <iostream>
using namespace std;


void sort_three (int& a, int& b, int& c)
{
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    if(c > a){
        int temp = a;
        a = c;
        c = temp;
    }
    if(c > b){
        int temp = b;
        b = c;
        c = temp;
    }

    return;
}

 

int main ()

{

   int i1 = 100, i2 = 90, i3 = 500;

   sort_three (i1, i2, i3);

   cout << "Three numbers are: " << i1 << " , " << i2 << " , " << i3 << endl;

}

