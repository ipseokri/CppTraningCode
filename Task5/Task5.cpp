#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
    string convertText;
    string inputText = "";
    fstream inputStream;

    inputStream.open("input.txt");
    if(inputStream.fail()){
        cerr << "file open is failed" << endl;
        exit(100);
    }
    
    while(!inputStream.eof()){
        inputStream >> convertText;
        if(convertText == "hate") convertText = "love";
        inputText += convertText;
        inputText += " ";
    }

    cout << inputText << endl;

    inputStream.close();

    return 0;
}