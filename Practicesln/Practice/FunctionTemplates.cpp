#include<iostream>

using namespace std;

/*void fun(int a){
    cout<< " a value is: " << a << endl;
}

void fun(char a){
    cout<< " a value is: " << a << endl;
}

void fun(float a){
    cout<< " a value is: " << a << endl;
}

void fun(double a){
    cout<< " a value is: " << a << endl;
}*/

template<typename T>
void fun(T value) {
    cout << " value is: " << value << endl;
}

// func template specialization
template<>
void fun(char c)
{
    cout << " This is specialized template fun for char and the value is " << c << endl;
}

//int main() {
//    fun<int>(2);
//    fun<char>('c');
//    fun<float>(4.8f);
//    fun<double>(4.5);
//    return 0;
//}
