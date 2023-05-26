// Question: Make cls non inheritable with out using final keyword
// REQUIRMENR:
// 1. we need one class which will make our class as final class
// lets call that class as Final class

// SOLUTION:
// a. Make default constructor of Final class as private
// b. Inherit Final class as Virtual in our class which we want to make inheritable
// c. Make our class as friend inside Final class.
		// (so that only our class can call the constructor not the final class

#include<iostream>

class Final
{
	Final() {}
	friend class Base;
};

class Base : virtual public Final
{
public:
	Base();
};

class Derived : public Base
{
public:
	Derived(){};
};

int main()
{
	Derived d;
	return 0;
}