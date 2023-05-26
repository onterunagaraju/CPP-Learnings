#include<iostream>


class Fraction
{
	int num;
	int den;
public:
	Fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
	}
	// conversion operator which converts to the type you specified, no need to write return type
	// 
	operator float() const
	{
		return ((float)num / den);
	}
};

//int main()
//{
//	Fraction f(5, 2);
//	float ans = f;
//	std::cout << ans << std::endl;
//	return 0;
//}