// Question : Overload Pre and post increament operator

#include<iostream>

class Int
{
	int elem;
public:
	Int() {}
	Int(int i): elem{i}{}
	void PrintValue()
	// void PrintValue(Int* const this)  this pointer is passed as hidden parameter
	{
		std::cout << "The value is " << elem << std::endl;
	}

	Int& operator ++() // pre increament
	{
		elem++;
		return *this;
	}

	Int operator++ (int dummy) //Post Increament
	{
		Int temp = *this;
		++(*this);
		return temp;
	}
};

//int main()
//{
//	Int i(100);
//	i.PrintValue(); // the call is like this PrintValue(&i);
//	(i++).PrintValue();
//	i.PrintValue();
//
//	(++i).PrintValue();
//	i.PrintValue();
//
//	return 0;
//}


// Question: this pointer in c++
// Ans: 1 Passed as hidden argument to non static member functions
//		2 points to the current obj
//		3 Is a const pointer which holds the address of current obj [TYPE* const this]
//		4 if the member function is const then this pointer type becomes [const Type* const this] 