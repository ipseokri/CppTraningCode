#include <iostream>
using namespace std;

class DayOfYear{
public:
    int month;
    int day;

    void adjustDay(int input);
    string output(void);
};

void DayOfYear::adjustDay(int input){
    if(input >= 0){
        switch (month)
        {
        case 1:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 2:
            day += input;
            if(day > 28){
                month += 1;
                day -= 28;
            }
            break;
        case 3:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 4:
            day += input;
            if(day > 30){
                month += 1;
                day -= 30;
            }
            break;
        case 5:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 6:
            day += input;
            if(day > 30){
                month += 1;
                day -= 30;
            }
            break;
        case 7:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 8:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 9:
            day += input;
            if(day > 31){
                month += 1;
                day -= 30;
            }
            break;
        case 10:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        case 11:
            day += input;
            if(day > 31){
                month += 1;
                day -= 30;
            }
            break;
        case 12:
            day += input;
            if(day > 31){
                month += 1;
                day -= 31;
            }
            break;
        }
    }


    if(input < 0){
        input *= -1;
        if(day - input <= 0){
            month -= 1;
            if(month < 1){
                month = 12;
            }

            switch (month)
            {
            case 1:
                day -= input;
                day += 31;
                break;
            case 2:
                day -= input;
                day += 28;
                break;
            case 3:
                day -= input;
                day += 31;
                break;
            case 4:
                day -= input;
                day += 30;
                break;
            case 5:
                day -= input;
                day += 31;
                break;
            case 6:
                day -= input;
                day += 30;  
                break;
            case 7:
                day -= input;
                day += 31;
                break;
            case 8:
                day -= input;
                day += 31;
                break;
            case 9:
                day -= input;
                day += 30;
                break;
            case 10:
                day -= input;
                day += 31;
                break;
            case 11:
                day -= input;
                day += 30;
                break;
            case 12:

                day -= input;
                day += 31;
                break;
            }
        }
        else{
            day -= input;
        }
    }
}

string DayOfYear::output(void){
    string output = "";
    switch (month)
    {
    case 1:
        output += "January ";
        output += to_string(day);
        break;
    case 2:
        output += "Februry ";
        output += to_string(day);
        break;
    case 3:
        output += "March ";
        output += to_string(day);
        break;
    case 4:
        output += "April ";
        output += to_string(day);
        break;
    case 5:
        output += "May ";
        output += to_string(day);
        break;
    case 6:
        output += "June ";
        output += to_string(day);
        break;
    case 7:
        output += "July ";
        output += to_string(day);
        break;
    case 8:
        output += "August ";
        output += to_string(day);
        break;
    case 9:
        output += "September ";
        output += to_string(day);
        break;
    case 10:
        output += "October ";
        output += to_string(day);
        break;
    case 11:
        output += "Novmember ";
        output += to_string(day);
        break;
    case 12:
        output += "December ";
        output += to_string(day);
        break;
    }

    return output;
}

int main ()
{
    DayOfYear d1;
    d1.month = 4;
    d1.day = 19;

    d1.adjustDay(20);    /* add 20 days to d1 */
    cout << "Adjusted date is " << d1.output() << endl;
}

