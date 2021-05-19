#include <iostream>
using namespace std;


void fillArray(int * arr, int len){
    cout << "Put array elements: ";
    for( int i = 0; i < len; i ++){
        cin >> *(arr + i);
    }
}

void printArray(int * arr, int len){
    cout << "Array elements are ";
    for( int i = 0; i < len; i ++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}



int main(void){
    int arr[5];
    fillArray(arr , 5);
    printArray(arr, 5);
}