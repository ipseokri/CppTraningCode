#include <iostream>
using namespace std;

class NComplex{
private:
    double realN;
    double imagN;

public:
    NComplex():realN(0), imagN(0){};
    NComplex(double real, double imaginary):realN(real), imagN(imaginary) {};


    NComplex operator+(const NComplex& ref){
        double t_realN = realN + ref.realN;
        double t_imagN = imagN + ref.imagN;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };
    NComplex operator-(const NComplex& ref){
        double t_realN = realN - ref.realN;
        double t_imagN = imagN - ref.imagN;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };
    NComplex operator*(const NComplex& ref){
        double t_realN = realN * ref.realN + (-1) * imagN * ref.imagN;
        double t_imagN = realN * ref.imagN + imagN * ref.realN;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };
    NComplex operator/(const NComplex& ref){
        if(ref.imagN == 0 && ref.realN == 0){
            cout << "divided by zero" << endl;
            exit(0);
        }
        double devider = ref.realN * ref.realN - (-1) * ref.imagN * ref.imagN;
        double t_realN = realN * ref.realN + imagN * ref.imagN;
        t_realN = t_realN / devider;
        double t_imagN = (-1) * realN * ref.imagN + imagN * ref.realN;
        t_imagN = t_imagN / devider;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };
    NComplex operator+(double input){
        double t_realN = realN + input;
        NComplex temp(t_realN, imagN);
        return temp;;
    };
    NComplex operator-(double input){
        double t_realN = realN - input;
        NComplex temp(t_realN, imagN);
        return temp;
    };
    NComplex operator*(double input){
        double t_realN = realN * input;
        double t_imagN = imagN * input;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };
    NComplex operator/(double input){
        if(input == 0){
            cout << "divided by zero" << endl;
            exit(0);
        }
        double t_realN = realN / input;
        double t_imagN = imagN / input;
        NComplex temp(t_realN, t_imagN);
        return temp;
    };

    friend NComplex operator+ (double input, const NComplex& ref);
    friend NComplex operator- (double input, const NComplex& ref);
    friend NComplex operator* (double input, const NComplex& ref);
    friend NComplex operator/ (double input, const NComplex& ref);
    friend ostream& operator<< (ostream& os, const NComplex &ref);
};

NComplex operator+ (double input, const NComplex& ref){
    double realN = input + ref.realN;
    double imagN = ref.imagN;
    NComplex temp(realN, imagN);
    return temp;
}
NComplex operator- (double input, const NComplex& ref){
    double realN = input - ref.realN;
    double imagN = (-1) * ref.imagN;
    NComplex temp(realN, imagN);
    return temp;
}
NComplex operator* (double input, const NComplex& ref){
    double realN = input * ref.realN;
    double imagN = input * ref.imagN;
    NComplex temp(realN, imagN);
    return temp;
}
NComplex operator/ (double input, const NComplex& ref){
    if(ref.imagN == 0 && ref.realN == 0){
        cout << "divided by zero" << endl;
        exit(0);
    }
    double devider = ref.realN * ref.realN - ref.imagN * ref.imagN;
    double realN = input * ref.realN;
    realN = realN / devider;
    double imagN = input * (-1) * ref.imagN;
    imagN = imagN / devider;
    NComplex temp(realN, imagN);
    return temp;
}

ostream& operator<< (ostream& os, const NComplex &ref){
    os << ref.realN << " + " << ref.imagN << "i" ;
    return os;

}


int main()
{
    NComplex n1 (5.1, 2.2), n2(2.0, 2.0), n3;
    double d1 = 3.0;

    cout << "n1+n2: " << n1+n2 << endl;
    cout << "n1*n2: " << n1*n2 << endl;
    cout << "n1-d1: " << n1-d1 << endl;
    cout << "d1*n2: " << d1*n2 << endl;
    //cout << "n1/n3: " << n1/n3 << endl;

    NComplex t1(3,4), t2(5,6), t3(2,3), t4(4,5);
    NComplex k1(1,1), k2(1, -1), k3(1,2), k4(3,4);
    cout << t1 + t2 << endl;
    cout << k1 - k2 << endl;
    cout << t3 * t4 << endl;
    cout << k3 / k4 << endl;
    cout << k1 / k2 << endl;
    cout << " ====== " << endl;
    cout << 1 + k1 << endl;
    cout << 1 - k1 << endl;
    cout << 2 * k1 << endl;
    cout << 4/k2<<endl;
    cout << " ====== " << endl;
    cout << k1 + 1 << endl;
    cout << k1 - 1 << endl;
    cout << k1 * 2 << endl;
    cout << k1 / 4 << endl;

    cout << 5 / n3 << endl;
 }