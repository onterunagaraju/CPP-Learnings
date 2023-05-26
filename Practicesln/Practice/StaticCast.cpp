#include<iostream>
#include<string>
// Casting two types 1. implicit conversion 2.Explicit conversion


class A {
    int x;
public:
    A() {

    }
    A(int _x) {
        x = _x;
        std::cout << " constructor called " << std::endl;
    }
    operator std::string()      // this is for type conversion of obj to required type
    //Syntax: operator TypeYouWantToConvert(){}   No need to specify the return type it automatically gets.
    {
        std::cout << "Conversion Operator" << std::endl;
        return std::to_string(x);
    }
    virtual void print() {

    }
};

class B :public A {
public:
    B() {

    }
    void print() {
        std::cout << "In calss B, print fun \n";
    }
};


//int main()
//{
//    A aobj(5);
//    aobj = 10; // call constructor C style struct intialization style
//    std::string s = aobj; // convertion operator will call here
//
//    // using static_cast for typecasting
//    std::string str2 = static_cast<std::string>(aobj); // static_cast able to call conversion operator
//
//    std::cout << "string= " << s << std::endl; // 10
//    aobj = static_cast<A>(50); 
//
//    // conversions involving inheritance: is-a
//    B bobj;
//    A* aptr = (A*)(&bobj); // Allowed
//    //A* aptr1 = static_cast<A*>(&bobj); // error: A is inaccessible base of B
//
//
//
//    int a = 'a';
//    char c = 99;
//    float f = 12.5;
//    double d = a;
//    double d1 = 9.5;
//    int b = d1;
//    bool bol = b;
//    int a1 = bol;
//    std::cout << a << " " << c << " " << f << " " << d << std::endl;
//    std::cout << "Double " << d1 << " int " << b << " Bool " << bol << " int " << a1 << std::endl;
//    int n1 = 2;
//    int n2 = 3;
//    int f1 = 2.0;
//    int n3 = f1 + n2;
//    std::cout << n3 << std::endl;
//    float f2 = float(n2) / n1;
//    std::cout << f2 << std::endl;
//
//    // Implicit conversions between types
//    float f3 = 10.5;
//    int i;
//    i = f3;
//    std::cout << i << std::endl;
//    i = static_cast<int>(f3);
//    std::cout << i << std::endl;
//
//    //prevent dangarous cast, more Restrictive
//    char c1;
//    A a_obj(25);
//    std::shared_ptr<A> u_ptr = std::make_shared<B>();
//    /*std::shared_ptr<B>*/ B* f_ptr = dynamic_cast<B*>(u_ptr.get());
//    //std::cout << "shared pointer "<< f_ptr->print() << std::endl;
//    f_ptr->print();
//    int* p1 = (int*)(&c1);
//    //*p1 = 3; // pass at compile time, fail at run time
//    //std::cout << *p1 << std::endl;
//    //int* p2 = static_cast<int*>(&c1); // compile time error
//
//
//    //converting to void* or from void*
//    int i1 = 10;
//    void* v = static_cast<void*>(&i1);
//    char* p = static_cast<char*>(v);
//    std::cout << "char pointer " << *p << sizeof(p);
//}