#include <iostream>
#include <mm_malloc.h>
using namespace std;

int* allocArray(int size){
    int * temp  = new int[size];
    return temp;
}

void printArray(int * arr){
    for(int i = 0; arr[i] != '\0'; i ++){
        cout << arr[i] << " ";
    }
    return;
}

void freeArray(int * arr){
    delete[] arr;
    return;
}

int main()
{
    int* arr;
    int size;

    cout << "Enter the array size: ";
    cin >> size;
    arr = allocArray(size);

    for (int i=0; i<size; i++)
    {
        cout << "Put an array element: ";
        cin >> arr[i];
    }

    printArray(arr);
    freeArray(arr);

    return 0;
}


