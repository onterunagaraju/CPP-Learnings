// Template meta programming

#include<iostream>

// to calculate 2^n at copile time using recursion using template meta programming

template<int n>
struct fun
{
	enum {val = 2*fun<n-1>::val};
};

template<>
struct fun<0>
{
	enum{ val = 1};
};

//int main()
//{
//	std::cout << fun<8>::val << std::endl;
//	return 0;
//}