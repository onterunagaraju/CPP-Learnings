#include<iostream>
#include<exception>
class Base {
public:
    virtual void f() {

    }
};

class Derived1 : public Base {

};

class Derived2 : public Base {

};
//int main()
//{
//    Base* bptrd1 = new Derived1;
//    Base* bptrd2 = new Derived2;
//    Derived1* dptr;
//    dptr = dynamic_cast<Derived1*>(bptrd1);
//    if (!dptr) {
//        std::cout << "Not Null\n";
//    }
//    dptr = dynamic_cast<Derived1*>(bptrd2);
//    if (dptr == NULL) {
//        std::cout << " Null Pointer\n";
//    }
//
//    Derived1 d;
//    Base b;
//    try {
//        Base& br = dynamic_cast<Base&>(d);
//        Derived1& dr = dynamic_cast<Derived1&>(b);// Exception bad_cast
//    }
//    catch (std::bad_cast& e) {
//        std::cout << e.what() << "Bad_cast exception\n";
//    }
//
//    return 0;
//}