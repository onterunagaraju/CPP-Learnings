// Question: How to check two different objects belongs to same class in c++  
// Ans: by using typeid();

#include<iostream>

class A {};
class B{};

//int main()
//{
//	A a1, a2;
//	B b1, b2;
//
//	if (typeid(a1) == typeid(b1)) // checkes for type of two objects
//		std::cout << "equal" << std::endl;
//	else
//		std::cout << "Not equal" << std::endl;
//	
//	if (typeid(a1) == typeid(a2))
//		std::cout << "Equal" << std::endl;
//	else
//		std::cout << "Not Equal" << std::endl;
//
//	if (&a1 == &a2)
//		std::cout << "Equal" << std::endl;
//	else
//		std::cout << "Not Equal" << std::endl;
// 	return 0;
//
//}