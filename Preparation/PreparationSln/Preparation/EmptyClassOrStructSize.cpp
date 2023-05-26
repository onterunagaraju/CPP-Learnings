// Question: why the empty class or struct size is not zero in the c++ (the size is 1)
// Ans: Two defferentiate the two objects. 

#include<iostream>

class A
{
	int a; // if class even has one member it is enough to differentiate objs. every obj contains their corresponding members
};

class B {}; // if class is empty to differentiate objects it's size is 1;

//int main()
//{
//	B b1, b2;
//	std::cout << sizeof(A) << std::endl;
//	std::cout << sizeof(B) << std::endl;
//	if (&b1 == &b2)
//	{
//		std::cout << "Yes" << std::endl;
//	}
//	else {
//		std::cout << "No" << std::endl;
//	}
//	return 0;
//}