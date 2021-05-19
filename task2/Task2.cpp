#include <iostream>

using namespace std;
double one_mile = 1.60934; 

int main(void){
    double distance = 184.6; 

    double distance_to_mile = distance / (one_mile * 1000);

    cout << "The distance is " << distance_to_mile <<" miles"<< endl;
    
    return 0;
}