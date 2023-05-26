#include<iostream>

using namespace std;
class A {
public:
    void sum(int a, int b) {
        cout << "In int,int  and sum: " << a + b << endl;
    }
    /*int sum(int a, int b){
        cout << "In int,int with return  and sum: " << a+b << endl;
        return a+b;
    }*/
    void sum(int a, int b, int c) {
        cout << "In int,int,int  and sum: " << a + b + c << endl;
    }

    void sum(float a, float b) {
        cout << "In float,float  and sum: " << a + b << endl;
    }
    void sum(double a, double b) {
        cout << "In double,double  and sum: " << a + b << endl;
    }
    void sum(float a, double b) {
        cout << "In float,double  and sum: " << a + b << endl;
    }
    void sum(double a, float b) {
        cout << "In double,float  and sum: " << a + b << endl;
    }

};
//int main()
//{
//    A a;
//    a.sum(2, 3);
//    a.sum(2, 3, 4);
//    a.sum(2.4, 2.6);
//    a.sum(2.4f, 2.6f);
//    a.sum(2.4f, 2.6);
//    a.sum(2.4, 2.6f);
//    //a.sum('a', 'b');
//    return 0;
//}

