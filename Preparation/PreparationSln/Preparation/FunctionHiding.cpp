// Question : Function Hiding

#include<iostream>

//class Base
//{
//public:
//	void fun(int i)
//	{
//		std::cout << "Base cls" << std::endl;
//	}
//};
// 
//class Derived : public Base
//{
//public:
//	void fun(char c)
//	{
//		std::cout << "Derived cls" << std::endl; // this fun function hides the fun function in Base class.
//	}
//};


// if you want to not hide the base function in derived class , use using Base::fun or you can call using scope resolution while calling

class Base
{
public:
	void fun(int i)
	{
		std::cout << "Base cls" << std::endl;
	}
	void fun1()
	{
		std::cout << "Base cls fun1" << std::endl;
	}
};

class Derived : public Base
{
public:
	using Base::fun; //now Base function not hidden if you use using Base::fun
	void fun(char c)
	{
		std::cout << "Derived cls" << std::endl; // this fun function hides the fun function in Base class.
	}
	void fun1()
	{
		std::cout << "Derived cls fun1" << std::endl;
	}
};


//int main()
//{
//	Derived d;
//	d.fun(1); // calls derived function as Base class function hidden
//	d.fun('c'); // calls derived function as Base cls function is hidden
//	// you call Base fun like below
//	d.Base::fun(2);
//	d.fun1();
//	Base* b = new Derived();
//	b->fun('c'); // b->fun(1)  these will always call Base cls fun
//
//	const char* str1 = "hello";
//	const char* str2 = "hello";
//	std::cout << &str1 << " " << &str2 << std::endl;
//	const char* str3 = str1;
//	std::cout << &str1 << " " << &str3 << std::endl;
//
//	std::string s = "hello1";
//	std::string s1 = "hello1";
//	std::cout << &s << " " << &s1 << std::endl;
//	std::string s2 = s;
//	std::cout << &s << " " << &s2 << std::endl;
//	// Raw string in c++ to take the hole string as it is without taking including the special meanings of characters
//	std::string s3 = R"(Hello\nWorld)"; // \n is a new line character R as rawstring it takes whole string as it is. \n functionality not included
//	std::cout << s3 << std::endl;
//	s3 = "Hello\nWorld"; //now \n new line character included and it print hello and world in two lines
//	std::cout << s3 << std::endl;
//	return 0;
//}