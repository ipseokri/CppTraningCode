#include <iostream>
using namespace std;

class PFArrayI{
private:
    int * arr;
    int pIndex;
    int len;
public:
    PFArrayI():len(50), pIndex(0) { arr = new int[len]; };
    PFArrayI(int init):len(init),pIndex(0) { arr = new int[len]; };
    PFArrayI(const PFArrayI& ref){
        arr = new int[ref.len];
        copy(ref.arr, ref.arr + ref.len, arr);
        len = ref.len;
        pIndex = ref.pIndex;
    };
    void addElement(int element){
        if(pIndex >= len){
            cout << "out of index" << endl;
            exit(0);
        }
        arr[pIndex] = element;
        pIndex++;
    };
    bool full() const{
        if(pIndex == len){
            return true;
        }
        return false;
    }
    int getCapacity(){
        return len;
    }
    int getNumberUsed(){
        return pIndex;
    }
    void emptyArray(){
        for(int i = 0; i < pIndex; i ++){
            arr[i] = 0;
        }
    }
    int& operator[](int a){
        return arr[a];
    }
    PFArrayI& operator= (const PFArrayI& ref){
        arr = new int[ref.len];
        copy(ref.arr, ref.arr + ref.len, arr);
        len = ref.len;
        pIndex = ref.pIndex;
        return *this;
    }
    ~PFArrayI() { delete[] arr; };
};


int main(void){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayI temp(cap);
    PFArrayI temp2(cap);
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    int next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
    temp.addElement(next);
    cin >> next;
    }
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
}