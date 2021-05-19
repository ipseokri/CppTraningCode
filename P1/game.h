#include <iostream>

using namespace std;

class cardgame{
private:
    // 카드내용의 유지와 게임 진행을 위한 카드배열
    char behindmap[4][4]; 
    char displayMap[4][4];
    bool opend[4][4];
    // 랜덤배치시 사용하는 배열
    int check[9];

    int p1Score; // 점수 관련 변수
    int p2Score;

    int firstPos; // 첫번째 입력 (카드의 위치)
    int secondPos; // 두번째 입력 

    int turns; // 총 게임의 턴수

    bool gameStatus; // 게임의 현재 상태
    bool checked; // 카드의 짝이 있는지 저장

public:
    cardgame(int gamemode); // 생성자
    void gameStart(); // 게임 시작 함수
    bool checkMap(); // 카드 체크 함수
    void printMap(); // 전체 카드 출력 함수
    void countingScore(int Pos1, int Pos2, int& Score, int player); // 점수 카운팅함수
    void gameOver(); // 게임종료 함수
};