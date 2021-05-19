#include <iostream>


using namespace std;

class Vector2D{
private:
    int x;
    int y;
public:
    Vector2D():x(0), y(0) {};
    Vector2D(const Vector2D& ref) { x = ref.x, y = ref.y;};
    Vector2D(int x, int y):x(x), y(y) {};

    void output(){
        cout << "( " << x << ", " << y << " )" << endl;
    }


    Vector2D& operator=(const Vector2D& ref){
        x = ref.x;
        y = ref.y;

        return *this;
    }

    int operator*(Vector2D& ref){
        return x * ref.x + y * ref.y;
    }


    friend Vector2D operator+(const Vector2D& ref, const Vector2D& ref2);
    friend Vector2D operator-(const Vector2D& ref, const Vector2D& ref2);
    friend bool operator==(const Vector2D& ref, const Vector2D& ref2);
    friend Vector2D operator* (int k, const Vector2D & ref);

};

Vector2D operator+(const Vector2D& ref, const Vector2D& ref2){
    Vector2D temp(ref.x + ref2.x , ref.y + ref2.y);
    return temp;
}
Vector2D operator-(const Vector2D& ref, const Vector2D& ref2){
    Vector2D temp(ref.x - ref2.x, ref.y - ref2.y);
    return temp;
}
bool operator==(const Vector2D& ref, const Vector2D& ref2){
    if(ref.x == ref2.x && ref.y == ref2.y){
        return true;
    }
    return false;
}
Vector2D operator* (int k, const Vector2D & ref){
    Vector2D temp( k * ref.x, k * ref.y);
    return temp;
}



int main()
{
  Vector2D v0, v1(2,2), v2(3,3), v3;
  int k = 2;

  v3 = k*v1;

  v3.output();

  cout << v1 * v2 << endl;

}