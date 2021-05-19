#include <iostream>


using namespace std;

class Vector2D{
private:
    int x;
    int y;
public:
    Vector2D():x(0), y(0) {};

    Vector2D(int x, int y):x(x), y(y) {};

    void output(){
        cout << "( " << x << ", " << y << " )" << endl;
    }


    Vector2D& operator=(const Vector2D& ref){
        x = ref.x;
        y = ref.y;

        return *this;
    }

    Vector2D& operator+(const Vector2D& ref){
        x += ref.x;
        y += ref.y;

        return *this;
    }

    Vector2D& operator-(const Vector2D& ref){
        x -= ref.x;
        y -= ref.y;

        return *this;
    }

    bool operator==(const Vector2D& ref) const{
        if(x == ref.x && y == ref.y){
            return true;
        }

        return false;
    }


};

int main()
{
  Vector2D v0, v1(2,2), v2(3,3), v3;
 
  v3 = v1 + v2;
  v3.output();
 
 
  v3 = v2 - v2;
  v3.output();
  if (v3 == v0)
     cout << "Operator - works!";
     
}