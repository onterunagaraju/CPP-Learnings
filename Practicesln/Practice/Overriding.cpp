#include<iostream>

class Base
{
public:
	int x = 2;
	virtual void Display()  // virtual funtion that is to be override is public
	{
		std::cout << "Base class Display" << std::endl;
	}
};

class Derived : public Base
{
//public:
	int x = 0;
	void Display() override // here you can declare as private also
	{
		std::cout << "Derived class Display" << std::endl;
	}
};

//int main()
//{
//	Base b;
//	//b.Display();
//	Base* obj = new Derived();
//	obj->Display();
//	std::cout << obj->x << std::endl;
//	Base b1 = Derived();
//	std::cout << b1.x << std::endl;
//	return 0;
//}