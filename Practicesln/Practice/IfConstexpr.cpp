#include<iostream>
#include<string_view>
//if constexpr is a C++17 keyword that allows you to conditionally compile code at compile-time based on a compile-time 
//constant expression. It is similar to the regular if statement, but is evaluated at compile-time rather than at run-time.

template <typename T>
void print_value(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Value is an integral type: " << value << '\n';
    }
    else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Value is a floating-point type: " << value << '\n';
    }
    else {
        static_assert(std::is_void_v<T>, "Value must be an integral or floating-point type.");
    }
}

//int main() {
//    int x = 42;
//    float y = 3.14;
//    double z = 2.718;
//  
//    print_value(x);
//    print_value(y);
//    //print_value(z); // This line will cause a static assertion error at compile-time
//    std::string s = "Hello";
//    //std::string_view str = s.substr(0, 4);
//    return 0;
//}