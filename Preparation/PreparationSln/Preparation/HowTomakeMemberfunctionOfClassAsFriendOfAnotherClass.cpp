// Question: How to make member function of a class as friend of another class

#include<iostream>

//class Base1
//{
//	int x;
//public:
//	Base1(int x=0): x{x} {}
//	friend void Base2::Print(Base1&); // we can declare like this but here compilation starts from top and it didn't know 
//									// what is Base2. for that declare Base1 class after Base2.
//};

class Base1;
class Base2
{
	int y;
public:
	Base2(int y=0) : y{y} {}
	void Print(Base1& b);//you want this print fun as friend of Base1 class. To do that you can 
						//declare in Base1 as Base2 as friend of Base1. But that will Able to access in whole 
						//Base2 class. Instead of that we need only Print fun as friend.

	/*{
		std::cout << "X " << b.x << std::endl;
	}*/
};

class Base1
{
	int x;
public:
	Base1(int x = 0) : x{ x } {}
	friend void Base2::Print(Base1&); // we can declare like this but here compilation starts from top and it didn't know 
									// what is Base2. for that declare Base1 class after Base2. if we declare like this Base1 after Base2
									// but in Base2 class Base1 obj is there . so to overcome this declare Print fun in Base2
									// and define Print fun of Base2 after Base1; to know Base1 in Base2 just declare Base1 at the top.
};

void Base2::Print(Base1& b)
{
	std::cout << "X " << b.x << std::endl;
}

//int main()
//{
//	Base1 b1(10);
//	Base2 b2(20);
//	b2.Print(b1);
//	return 0;
//}