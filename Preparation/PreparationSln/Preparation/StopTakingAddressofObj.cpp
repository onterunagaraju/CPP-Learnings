#include<iostream>

// Question: How to stop someone from taking the address of obj?
// A1: Overload & operator and keep it as private
// A2: Delete & operator from your cls

class Base
{
	int x;
public:
	Base() {};
	Base(int x) :x{ x } {};
//private: // it is private and inaccessable from outside of cls so you cant copy the address of obj;
//	Base* operator &()
//	{
//		std::cout << "Bingo" << std::endl;
//		return this;
//	}

	// Other way is to delete the & operator like below
	//Base* operator &() = delete;
};

//int main()
//{
//	Base b;
//	Base* bp = &b;
//	std::cout << bp << std::endl;
//	std::cout << &b << std::endl;
//	return 0;
//}