#include <iostream>

using namespace std;

int main(void){
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;

    for (int i = 0; i < n-2 ; i++){
        int *p = &a[i];
        cout << *(p) + *(p+1) + *(p+2) << endl;
    }
}