#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(void){
    map<int, string> std_list;

    int id_num;
    string std_name;

    cout << "Enter the ID number :" ;
    cin >> id_num;
    while(id_num != 0){
        cout << "Enter the student name :" ;
        cin >> std_name;
        std_list.insert(make_pair(id_num, std_name));
        cout << "Enter the ID number :" ;
        cin >> id_num;
    }

    cout << "Enter the searching ID number:";
    cin >> id_num;

    cout << "The Student name is " << std_list.find(id_num)->second << endl;
    return 0;
}