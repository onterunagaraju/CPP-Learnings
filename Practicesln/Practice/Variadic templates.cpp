#include<iostream>

// To handle base case of below recursive
// Variadic function Template
void print()
{
	std::cout << "It's empty print fun\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template<typename T, typename... args>
void print(T var1, args... var2)
{
	std::cout << var1 << "\n";
	print(var2...);
}

//int main()
//{
//	print(1, 2, 3, 4, "pass any number of params", "I can print");
//	return 0;
//}