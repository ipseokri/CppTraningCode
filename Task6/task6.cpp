#include <iostream>

using namespace std;

int main(void){
    int a[4][4] = {10, 20, 30, 40, 5, 4 ,3, 99, 55, 100, 42, 100, 0, 105, 2, 11};
    int largestNum = 0;
    int secondLargestNum = 0;

    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            if(a[i][j] > largestNum) largestNum = a[i][j];
            else if (a[i][j] > secondLargestNum) secondLargestNum = a[i][j];
        }
    }


    cout << "The largest number " << largestNum << endl;
    cout << "The Second-largest number " << secondLargestNum << endl;

    return 0;
}