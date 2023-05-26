#include <iostream>
using namespace std;

void fun() {
    cout << "In the function fun" << endl;
}

int sum(int a, int b) {
    return a + b;
}

void GreetMorning() {
    cout << "Hello , Good Morning" << endl;
}

void GreetEvening() {
    cout << "Hello , Good Evening" << endl;
}

void GreetNight() {
    cout << "Hello , Good Night" << endl;
}

void Greeter(void (*greet_ptr)()) {
    greet_ptr();
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

// return a function pointer from fun.
typedef int(*mathFun)(int, int);
mathFun function(int type)
// int(*function(int type))(int,int) {}     you can write like this also
{
    if (type == 1)
        return add;
    else
        return sub;
}


int main()
{
    // Normal calling;
    cout << "Normal calling" << endl;
    fun();
    cout << "Sum is " << sum(10, 20) << endl;
    cout << "using function pointers" << endl;
    // Creating fun pointers (pointers to fun)
    // syntax:  return_type_of_fun (*fun_name)(parameter_list);

    // pointer for fun;
    void (*fun_ptr)() = fun;
    //fun_ptr = &fun;
    // pointer for sum;
    int (*fun_ptr1)(int, int) = sum;
    cout <<  fun_ptr << endl;
    cout << fun_ptr1(20, 30) << endl;

    // passing funtion as parameter to funtion
    Greeter(GreetMorning);
    Greeter(GreetEvening);
    Greeter(GreetNight);

    //return function pointer from function
    int(*someFun)(int, int);
    someFun = function(1);
    someFun(1, 2);
    someFun = function(2);
    someFun(5, 2);

    // Array of function pointers (use typedef for type declaration)
    mathFun Array[2] = { add, sub }; // Array of function pointers and intialized with add, sub functions
    //int(*Array[2])(int, int) = { add,sub };  use can also declare like this array of function pointers
    int c = Array[0](2, 3);
    int d = Array[1](3, 2);
    std::cout << " Array of function pointers" << c << " " << d << std::endl;
    
    return 0;
}
