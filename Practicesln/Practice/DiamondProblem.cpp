#include<iostream>

class ClassA
{
public:
	int a;
	void Print()
	{
		std::cout << "ClassA print fun" << std::endl;
	}
};

class ClassB :virtual public ClassA
{
public:
	int b;
	
};

class ClassC :virtual public ClassA
{
public:
	int c;
	
};

class ClassD : public ClassB, public ClassC
{
public:
	int d;
	
};

//int main()
//{
//	ClassD obj;
//	//obj.a = 10; // Ambiguos call to a as D contains two copies of A , one from ClassB path and other from ClassC Path
//	// two ways to solve 
//	// 1. Scope resolution
//	// 2. Virtual inheritance so that only one copy of A is added to D
//	obj.ClassB::a = 10; // Ok
//	obj.ClassC::a = 15; // Ok
//	//obj.a = 100;
//	obj.b = 20;
//	obj.c = 30;
//	obj.d = 40;
//
//	std::cout << "a from path B " << obj.ClassB::a << std::endl;
//	std::cout << "a from path C " << obj.ClassC::a << std::endl;
//	std::cout << obj.b << std::endl;
//	std::cout << obj.c << std::endl;
//	std::cout << obj.d << std::endl;
//
//	obj.Print();
//	return 0;
//}