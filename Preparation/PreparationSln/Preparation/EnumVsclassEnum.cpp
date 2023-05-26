#include <iostream>

// Question: diff b/w plain Enum ans class Enum?

// for Plain Enum, Values are converted into integrals where as for class Enums , values do not converted into integrals
enum colors{yellow, black, white};
enum people{good, bad};
enum class colors1{yellow,black,white};
enum class people1{good, bad};

void fun(int n)
{
	// This switch works for plain enum as it converts and compare with integers and this will not works for class enum
	switch (n)
	{
	case yellow:
		std::cout << "Yellow" << std::endl;
		break;
	case black:
		std::cout << "Black" << std::endl;
		break;
	case white:
		std::cout << "white" << std::endl;
		break;
	}
}

void fun(colors1 c)
{
	//this switch works for class enum
	switch (c)
	{
	case colors1::yellow:
		std::cout << "yellow" << std::endl;
		break;
	case colors1::white:
		std::cout << "white" << std::endl;
		break;
	case colors1::black:
		std::cout << "black" << std::endl;
		break;
	}
}


//int main()
//{
//	//Plain Enum
//	enum Color{red, green, blue};   // Plain enum has full scope
//	// if you want create new variable that already contains in the plain enum it'll give error
//	//int green = 10;  // it'll give error as green is redefining as green alredy presents in the plain enum Color which has full scope
//	//enum Color2{red,green, blue, black};  // This will give error as red, green, blue alredy have in scope which are present in Color enum
//	// So we cant create them  where as it will be possible with class enum as it has only class scope.
//	Color c = red;
//	switch (c)
//	{
//		case red: std::cout << "red" << std::endl; break;
//		case green: std::cout << "green" << std::endl; break;
//		case blue: std::cout << "Blue" << std::endl; break;
//
//	}
//
//	/////////////////////////////////////
//	// Class Enum
//	enum class Color1{red, green, blue};	// Class enum has only class scope. It doesn't act like above. 
//											//we can define the variable which alredy presents in the class enum. it'll not give any error
//	//int green = 100; // here it'll not give any error if we comment the above enum Color
//
//	enum class Clor2{red, green, blue, black}; // this will not give any error as Color1 values have different class scope and color2 values have diff cls scope.
//	Color1 c1 = Color1::red;
//	switch (c1)
//	{
//	case Color1::red:
//		std::cout << "red" << std::endl;
//		break;
//	case Color1::green:
//		std::cout << "green" << std::endl;
//		break;
//	case Color1::blue:
//		std::cout << "blue" << std::endl;
//		break;
//	}
//
//	fun(yellow);
//	fun(colors1::yellow);
//
//	if (yellow == good)
//	{
//		std::cout << "red and good are equal" << std::endl; // this will execute but this logically not equal, this is one more prob.
//	}
//	//if (colors1::yellow == people::good) // for two different class enums no == operator exists this will not true and gives error
//	//{
//	//	std::cout << "This will not execuete";
//	//}
//	return 0;
//}