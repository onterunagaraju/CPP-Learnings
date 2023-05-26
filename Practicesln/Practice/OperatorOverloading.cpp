#include<iostream>

using namespace std;

class Complex {
public:
    int real;
    int imaginary;
    Complex() {}
    Complex(int _real, int _imaginary) {
        real = _real;
        imaginary = _imaginary;
    }

    /*void display() {
        cout << "real: " << real << " imaginary: " << imaginary << endl;
    }*/

    // Operator Overloading as member function
    /*Complex operator + (Complex obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;
        return temp;
    }*/

    // Operator Overloading as Friend function
    friend Complex operator + (const Complex obj1, const Complex obj2);
    friend ostream& operator << (ostream& out, Complex obj);
};

Complex operator+(const Complex obj1, const Complex obj2)
{
    return Complex(obj1.real + obj2.real , obj1.imaginary + obj2.imaginary);
}

ostream& operator << (ostream& out, Complex obj)
{
    out << "Real: " << obj.real << " Imaginginary: " << obj.imaginary << endl;
    return out;
}

//int main() {
//    Complex obj1(2, 3);
//    Complex obj2(4, 5);
//    cout << obj1 << endl;
//    cout << obj2 << endl;
//    /*obj1.display();
//    obj2.display();*/
//    Complex obj3 = obj1 + obj2; //obj1.+(obj2)
//    //obj3.display();
//    cout << obj3 << endl;
//    return 0;
//}