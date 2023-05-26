// Question : What is the use of  decltype in c++
// Ans:  It Checks the type of expression

#include<iostream>


template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a+b) // decltype checks the type of expression and return that type . You can return the type with auto only , no need to check with decltype. decltype checking is the full syntax.
{
	return a + b;
}

//Dangling reference
int& fun()
{
	int i = 10;
	return i;
}

int& k = fun(); //here from the fun function your returning reference to i which is local variable to fun and it will destroy
				// when we out from the fun. and K is refering to some undefined memory which is not present. this dangling refernce.

//int main()
//{
//	std::cout << add(1, 1.8) << std::endl; // print 2.8 as T2 is float and returning T2
//	std::cout << add(1.8, 1) << std::endl; // print 2 as T2 is integer and returning T2
//	return 0;
//}