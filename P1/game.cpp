#include "game.h"


cardgame::cardgame(int gamemode){

    for(int i = 0; i < 9; i++){
        check[i] = 0;
    }

    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            displayMap[i][j] = 'x';
        }
    }

    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            opend[i][j] = false;
        }
    }

    if(gamemode == 1){
        int input = 1;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j ++){
                behindmap[i][j] = '0' + input % 10;
                if( i <= 1){
                    input ++;
                } else{
                    input --;
                }
                if(input > 8) input --;
            }
        }
    }else{
        checked = true;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j ++){
                while(checked){   
                    int input = rand()%8 + 1;
                    if(check[input] < 2){
                        check[input]++;
                        behindmap[i][j] = '0' + input % 10;;
                        checked = false;
                    }
                }
                checked = true;
            }
        }
    }

}

void cardgame::gameStart(){
    gameStatus = true;
    turns = 20;

    printMap();

    while(gameStatus){

        cout << "P1's turn, choose two cards (" << turns << " turns remain) :";
        cin >> firstPos >> secondPos;

        countingScore(firstPos, secondPos, p1Score, 1);

        turns --;

        gameStatus = checkMap();
        if(!gameStatus) break;

        cout << "P2's turn, choose two cards (" << turns << " turns remain) :";
        cin >> firstPos >> secondPos;

        countingScore(firstPos, secondPos, p2Score, 2);

        turns --;

        gameStatus = checkMap();
    }

    gameOver();
}

void cardgame::printMap(){
    cout << "   1234" << endl;
    cout << "-+-----" << endl;
    for(int i = 0; i < 4  ; i ++){
        cout << i+1 << "| ";
        for(int j = 0; j < 4; j++){
            cout << displayMap[i][j];
        }
        cout << endl;
    }
}

void cardgame::countingScore(int Pos1, int Pos2, int& Score, int player){
    int firstX;
    int firstY;
    int secX;
    int secY;

    firstX = Pos1 / 10 - 1;
    firstY = Pos1 % 10 - 1;

    secX = Pos2 / 10 - 1;
    secY = Pos2 % 10 - 1;

    bool test = true;
    int tempPos1;
    int tempPos2;
    while(test){
        test = false;

        if(firstX > 3 | firstY > 3 | secX > 3 | secY > 3){
            cout << "Your Pair is out of Range" << endl;
            test = true;
        }

        if(opend[firstX][firstY] == true | opend[secX][secY] == true){
            if(opend[firstX][firstY] == true){
                cout << firstX + 1 << "," << firstY + 1 << " ";
            }
            if(opend[secX][secY] == true){
                cout << secX + 1 << "," << secY + 1 << " ";
            }
            cout << "your pair was already selected" << endl;

            test = true;
        }

        if(test){
            cout << "choose again cards : ";
            cin >> tempPos1 >> tempPos2;

            firstX = tempPos1 / 10 - 1;
            firstY = tempPos1 % 10 - 1;

            secX = tempPos2 / 10 - 1;
            secY = tempPos2 % 10 - 1;

        }
    }
    displayMap[firstX][firstY] = behindmap[firstX][firstY];
    displayMap[secX][secY] = behindmap[secX][secY];
    printMap();
    
    if(player == 1){
        cout << "P1";
    } else {
        cout << "P2";
    }
    if(displayMap[firstX][firstY] == displayMap[secX][secY]){
        opend[firstX][firstY] = true;
        opend[secX][secY] = true;
        Score++;
        cout << " found a matching pair! P1's score: " << p1Score << ", P2's score: "<< p2Score << endl;
        return;
    }
    
    cout << " failed to find a matching pair" << endl;

    displayMap[firstX][firstY] = 'x';
    displayMap[secX][secY] = 'x';

    return;
}

bool cardgame::checkMap(){
    if(turns == 0){
        return false;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j ++){
            if(displayMap[i][j] == 'x') return true;
        }
    }

    return false;
}


void cardgame::gameOver(){
    cout << "Game Finished, Final Scores are  P1's score: " << p1Score << ", P2's score: "<< p2Score << endl;
}
