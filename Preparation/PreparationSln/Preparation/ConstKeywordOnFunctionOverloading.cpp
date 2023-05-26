// Question: const Keyword on function overloading
// Points: 
// 1. C++ allows to overload member functions on the basis on const and non-const.
// 2. const parameters allows to overload member functions and normal functions but it should be reference or pointers

#include<iostream>


class Test
{
	int x;
public:
	Test(int x=0) : x{x} {}
	//void Print(int val)
	//{
	//	std::cout << val << std::endl;
	//}
	//void Print(const int val)
	//{
	//	std::cout << val << std::endl;		// this two print function not overloaded it gives error as const and non-const parameters are not references / pointers
	//}

	void Print(int& val)
	{
		std::cout << val << std::endl;
	}
	
	void Print(const int& val)   // this two print funs are overloded. here you can use with pointers also instead of references
	{
		std::cout << val << std::endl;
	}

	void Print1()
	{
		std::cout << "Non- Const " << std::endl;
	}
	void Print1() const // Now these two print1 mem functions are overloaded based on const and non-constness.
	{
		std::cout << "Const " << std::endl;
	}
};

//int main()
//{
//	Test t;
//	int k = 10;
//	const int p = 20;
//	t.Print(k);
//	t.Print(20);
//	t.Print1();
//	const Test t1;
//	t1.Print1();
//	return 0;
//}