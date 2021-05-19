#include <iostream>
#include <string>

using namespace std;


int main(void){
    int mathScore;
    int progLanScore;
    int dataStructScore;
    string grade;

    int totalScroe;
    float totalAvg;

    std::cout << "Put the Discrete math score : ";
    std::cin >> mathScore;
    std::cout << "Put the Programming Language score: ";
    std::cin >> progLanScore;
    std::cout << "Put the Data Structure score: ";
    std::cin >> dataStructScore;

    totalScroe = mathScore + progLanScore + dataStructScore;
    totalAvg = (float)totalScroe / 3.0;

    if(totalAvg > 95.0){
        grade = "A+";
    }else if(totalAvg > 90.0){
        grade = "A0";
    }else if(totalAvg > 85.0){
        grade = "B+";
    }else if(totalAvg > 80.0){
        grade = "B0";
    }else if(totalAvg > 75.0){
        grade = "C+";
    }else if(totalAvg > 70.0){
        grade = "C0";
    }else{
        grade = "F";
    }

    cout.precision(4); 
    cout << "The average score is "<< totalAvg << " and the grade is " << grade << endl;
    return 0;
}