
#include <iostream>

class A {
    int x1;
    int x2;
public:
    A() {
        x1 = 10;
        x2 = 20;
    }
    void printA() {
        std::cout << "x1= " << x1 << " x2= " << x2 << std::endl;
    }
};

class B {
    char c;
public:
    B() {
        c = 'A';
    }
    void printB() {
        std::cout << "c = " << c << std::endl;
    }
};

struct S {
    int i1;
    int i2;
    char c;
    bool b;
};

int main()
{
    int a = 70;
    int* p1 = &a;
    char* pc = reinterpret_cast<char*>(p1);
    std::cout << *pc << std::endl;

    int* p2 = reinterpret_cast<int*>(a);
    std::cout << p2 << std::endl;
    std::cout << reinterpret_cast<int>(p2) << std::endl;


    A a1;
    B b;
    // unsafe conversions
    A* pA = reinterpret_cast<A*>(&b);
    B* pB = reinterpret_cast<B*>(&a1);
    pA->printA();
    pB->printB();
    a1.printA();
    b.printB();


    S s;
    s.i1 = 10;
    s.i2 = 20;
    s.c = 'A';
    s.b = true;

    int* pS = reinterpret_cast<int*>(&s);
    std::cout << *pS << std::endl;
    pS++;
    std::cout << *pS << std::endl;
    pS++;
    char* pSC = reinterpret_cast<char*>(pS);
    std::cout << *pSC << std::endl;
    pSC++;
    bool* pSB = reinterpret_cast<bool*>(pSC);
    std::cout << *pSB << std::endl;


    return 0;
}

