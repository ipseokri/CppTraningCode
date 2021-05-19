#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#include <string>

using namespace std;

class Pet{
private:
    string name;
    string owner;
    double rate;
    int nights;
    bool checkIn;
    double fee;

public:
    Pet():name("No name Yet"), owner("No owner Yet"), rate(0), nights(0), checkIn(false) { fee = rate * nights; };
    Pet( string & theOwner, string & theName, double theRate, int theNights):name(theName), owner(theOwner), rate(theRate), nights(theNights), checkIn(true) { fee = rate * nights;};
    void setName(string& newName);
    void setOwner(string & newOwner);
    void setRate(double newRate);
    void setNights(int newNights);
    void setFee(void);
    string getName(void) const;
    string getOwner(void) const;
    double getRate(void) const;
    double getFee(void) const;
    int getNights(void) const;
    bool getCheckIn(void) const;
    void printPetInfo(void) const;
    void dayLeft(int Nights);
    void setCheckout(void);

};

class Owner{
private:
    string name;
    double balance;
    int hasPet;
    bool init;
public:
    Owner():name("No name Yet"), balance(0), hasPet(0), init(true) {};
    Owner(string& theName, double theBalance) : name(theName), balance(theBalance),hasPet(0), init(true) {};

    void setName(string & newName);
    void setBalance(double newBalance);
    void setHasPet(int num);
    string getName(void) const;
    double getBalance(void) const;
    void setInit(bool book);
    int getHasPet(void) const;
    void printOwnerInfo(void) const;
    void addPetNum(int num);
    void subPetNum(int num);
    void payingFee(double fee);
};

void Pet::setCheckout(void){
    checkIn = false;
}

void Pet::setName(string& newName){
    name = newName;
}
void Pet::setOwner(string & newOwner){
    owner = newOwner;
}
void Pet::setRate(double newRate){
    rate = newRate;
    setFee();
}
void Pet::setNights(int newNights){
    nights = newNights;
    setFee();
}
void Pet::setFee(void){
    fee = nights * fee;
}
string Pet::getName(void) const{
    return name;
}
string Pet::getOwner(void) const{
    return owner;
}
double Pet::getFee(void) const{
    return fee;
}
double Pet::getRate(void) const{
    return rate;
}
int Pet::getNights(void) const{
    return nights;
}
bool Pet::getCheckIn(void) const{
    return checkIn;
}
void Pet::dayLeft(int Nights){
    nights -= Nights;
    if(nights < 0){
        nights = 0;
    }
}
void Pet::printPetInfo(void) const{
    if(getNights() > 0 || checkIn != false){
        cout << "Pet {name: "<< getName() << ", owner: "<< getOwner() << ", rate: "<<getRate() << ", remainNights: " << getNights() << "}"<<endl;
    }
}

void Owner::setName(string & newName){
    name = newName;
}
void Owner::setBalance(double newBalance){
    balance = newBalance;
}
void Owner::setHasPet(int num){
    hasPet = num;
}
string Owner::getName(void) const{
    return name;
}
double Owner::getBalance(void) const{
    return balance;
}
int Owner::getHasPet(void) const{
    return hasPet;
}

void Owner::addPetNum(int num){
    hasPet += num;
}

void Owner::subPetNum(int num){
    hasPet -= num;
}

void Owner::payingFee(double fee){
    balance -= fee;
}

void Owner::printOwnerInfo(void) const{
    if(init || getHasPet()>0){
        cout << "Owner {name: "<< getName() << ", balance: "<< getBalance() << ", numPetsCheckin: "<< getHasPet() << "}"<<endl;
    }
}

void Owner::setInit(bool book){
    init = book;
}


int main(void)
{

    Pet hotelPetList[100];
    Owner hotelPetOwnerList[100];

    int WorkDays = 0;
    double balance = 0;

    ifstream readFile;
    int pet_num = 0;
    int owner_num = 0;

    readFile.open("input.txt");    //파일 열기
 
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            string str;
            getline(readFile, str);
            istringstream ss(str);
            string stringBuffer;
            vector<string> x;
            x.clear();
            //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
  
            while (getline(ss, stringBuffer, ' ')){
                x.push_back(stringBuffer);
            }



            if(!x[0].find("register")){
                hotelPetOwnerList[owner_num] = Owner(x[1], stod(x[2]));
                owner_num++;
            }
            else if(!x[0].find("checkin")){
                hotelPetList[pet_num] = Pet(x[1], x[2], stod(x[3]), stoi(x[4]));
                pet_num++;
                for(int i = 0; i < owner_num; i ++){
                    if(hotelPetOwnerList[i].getName() == x[1]){
                        hotelPetOwnerList[i].addPetNum(1);
                    }
                }
            }
            else if(!x[0].find("showpets")){
               for(int i = 0; i < pet_num; i++){
                   hotelPetList[i].printPetInfo();
                }
            }
            else if(!x[0].find("showowners")){
                for(int i = 0; i < owner_num; i++){
                   hotelPetOwnerList[i].printOwnerInfo();
                   hotelPetOwnerList[i].setInit(false);
                }
            }
            else if(!x[0].find("pass")){
                WorkDays += stoi(x[1]);
                for(int i = 0; i < pet_num; i++){
                    if(hotelPetList[i].getCheckIn()){
                        hotelPetList[i].dayLeft(stoi(x[1]));
                        // cout << "pet : " << hotelPetList[i].getName() << endl;
                        if(hotelPetList[i].getNights() <= 0){
                            for(int j = 0; j < owner_num; j++){
                                if(hotelPetList[i].getOwner() == hotelPetOwnerList[j].getName()){
                                    if(hotelPetOwnerList[j].getBalance() > hotelPetList[i].getFee()){
                                        hotelPetOwnerList[j].payingFee(hotelPetList[i].getFee());
                                        balance += hotelPetList[i].getFee();
                                        hotelPetOwnerList[j].subPetNum(1);
                                        hotelPetList[i].setCheckout();
                                        // cout << hotelPetList[i].getName() << "was checked out" << endl;
                                    }
                                }
                            }
                        }
                    }
                }

                cout << x[1] << " days have passed " << endl;
            }
            else if(!x[0].find("getbalance")){
                cout << "Working Days: " << WorkDays << ", Balance: " << balance << endl;
            }
        }
        readFile.close();    //파일 닫아줍니다.
    }
    return 0;
}
