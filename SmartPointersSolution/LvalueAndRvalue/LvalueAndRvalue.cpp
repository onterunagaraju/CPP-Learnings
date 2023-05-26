
#include <iostream>

int get() {
    return 10;
}

//lvalue ref
int fun(const int& a) {
    return a;
}


//rvalue ref
int fun(int&& a) {
    return a;
}


//perfect forwarding

void Display(int& i) {
    std::cout << i << " int&" << std::endl;
}

void Display(int&& i) {
    std::cout << i << " int&&" << std::endl;
}

template<typename T>
void DisplayWraper(T&& t) {  
    Display(std::forward<T>(t));
    //Display(t);
}

int main()
{
    int val = 10;
    //10 = val;
    int val1 = val;
    int val2 = val + val1;
    int var = get();
    //get() = 20;
    //int var1 = fun(30);
    int var1 = fun(val);
    int var2 = fun(30);

    int var3 = fun(40);

    int x = 5;
    DisplayWraper(x); // int& called
    DisplayWraper(5); // int&& called
}

