
#include <iostream>

class Test {
    int* data;
public:
    Test(const int size) {
        std::cout << "Resource aquired \n";
        data = new int[size]; // acquire resource
    }
    ~Test() {
        std::cout << "Resource released \n";
        delete[] data; //release
    }

    void do_Something() {
        std::cout << "Doing something\n";
    }

};

int main()
{
    Test t(5);
    return 0;
    {
        Test t1(10);
        return 0;
        t1.do_Something();
    }
    t.do_Something();

}

