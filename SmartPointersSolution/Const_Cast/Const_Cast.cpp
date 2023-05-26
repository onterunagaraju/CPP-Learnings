
#include <iostream>
// change non-const class members inside a const member function
class A {
    mutable int x;
public:
    void f(int i) const {
        // this->x = i; // error
        //const_cast<A*>(this)->x = i;
        x = i;
    }
};

void fun1(const int& a) {
    std::cout << "a inside fun " << a << std::endl;
}


int fun(int* p) {
    return (*p);
}

int main()
{
    const int a = 10;
    const int* ptr = &a;
    int* ptr1 = const_cast<int*>(ptr);
    //pass const data to a function that doesn't recieve const;
    std::cout << fun(ptr1) << std::endl;


    // undefined behaviour to modify a value initially declared as const
    const int a1 = 20;
    const int* p1 = &a1;
    int* p2 = const_cast<int*>(p1);
    *p2 = 30;
    fun1(a1);
    std::cout << *p2 << std::endl;
    std::cout << a1 << std::endl;
    std::cout << &a1 << std::endl;
    std::cout << p2 << std::endl;
    // Except that any class member daclared mutable can be modified, 
    // any attempt to modify a const object during its lifetime results in undefined behaviour.


    //... can't cast to a type different from original object
    //int a2 = 40;
    //const int* b = &a2;
    //char* c = const_cast<char*>(b);//compiler error
    return 0;
}

