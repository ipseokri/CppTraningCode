#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Figure{
public:
    Figure() {};
    virtual ~Figure() {};
    virtual void draw() = 0;
};

class Point{
public:
    int x;
    int y;

    Point():x(0), y(0) {};
    Point(int NewX, int NewY):x(NewX), y(NewY) {};
    ~Point() {};

    friend ostream& operator<< (ostream& os, const Point& p);
};

class Rectangle: public Figure{
public:
    Point p1c;
    Point p2c;

    Rectangle(): p1c(Point(0,0)), p2c(Point(0,0)) {};
    Rectangle(Point& p1, Point& p2):p1c(p1), p2c(p2) {};
    ~Rectangle() {};

    void draw();
};

class Circle: public Figure{
public:
    Point p1c;
    int rad;

    Circle(): p1c(Point(0,0)), rad(0) {};
    Circle(Point& p1, int NewRad):p1c(p1), rad(NewRad) {};
    ~Circle() {};
    void draw();
    
};

void Rectangle::draw(){
    cout << "A rectangle from " << p1c << " to " << p2c << endl;
}

void Circle::draw(){
    cout << "A circle with the center of " << p1c << " and the radius of " << rad << endl;
}

ostream& operator<< (ostream& os, const Point& p){
    os << "(" << p.x << ", "<< p.y << ")" ;
    return os;
}

void draw2figues (Figure& f1, Figure& f2)
{
    cout << "First figure is: ";
    f1.draw();
    cout << "Second figure is: ";
    f2.draw();
}
 
int main ()
{
    string mode;
    vector<Figure*> container;

    while(1){
        cout << "Enter figure type or draw: ";
        cin >> mode;
        
        if(mode == "rectangle"){
            int tempX, tempY;
            cout << "Enter x, y coordinates of P1 : " ;
            cin >> tempX >> tempY;
            Point p1(tempX, tempY);
            cout << "Enter x, y coordinates of P2 : " ;
            cin >> tempX >> tempY;
            Point p2(tempX, tempY);
            container.push_back(new Rectangle(p1, p2));
        }
        else if(mode == "circle"){
            int tempX, tempY;
            cout << "Enter x, y coordinates of P1 : " ;
            cin >> tempX >> tempY;
            Point p1(tempX, tempY);
            cout << "Enter the radius: " ;
            cin >> tempX;
            container.push_back(new Circle(p1, tempX));
        }
        else if(mode == "draw"){
            vector<Figure*>::iterator iter;
            vector<Figure*>::iterator iter2 = container.begin();
            for(iter = container.begin(); iter != container.end(); iter++){
                (*(*iter)).draw();
                delete *iter;
            }
            container.clear(); // 메모리 누수 발생  그렇다면 해제를 먼저 해주어야함.
            (*(*iter2)).draw();
        }
        else if(mode == "exit"){
            break;
        }
        else{
            cout << "=============please type anything================ \n" ;
        }
    }
    

    
}
