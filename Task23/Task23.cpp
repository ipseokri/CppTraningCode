#include <iostream>

using namespace std;

class Figure{
public:
    virtual void draw() = 0;
};

class Point{
public:
    int x;
    int y;

    Point():x(0), y(0) {};
    Point(int NewX, int NewY):x(NewX), y(NewY) {};

    friend ostream& operator<< (ostream& os, const Point& p);
};

class Rectangle: public Figure{
public:
    Point p1c;
    Point p2c;

    Rectangle(): p1c(Point(0,0)), p2c(Point(0,0)) {};
    Rectangle(Point& p1, Point& p2):p1c(p1), p2c(p2) {};

    void draw();
};

class Circle: public Figure{
public:
    Point p1c;
    int rad;

    Circle(): p1c(Point(0,0)), rad(0) {};
    Circle(Point& p1, int NewRad):p1c(p1), rad(NewRad) {};

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
    Point p1(0,0), p2(2,2);
    Rectangle r1 (p1, p2);
    Circle c1 (p1, 2);
    draw2figues(r1, c1);
}
