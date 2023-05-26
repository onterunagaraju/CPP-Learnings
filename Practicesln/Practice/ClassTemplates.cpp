#include<iostream>

template<typename T,int N>
class Array
{
	T arr[N]; // to create any type data arr and N(size) should know at compile time only
public:
	int GetSize()
	{
		return N;
	}
};

// template Specialization
template<int N>
class Array<char,N>
{
	char arr[N];
public:
	int GetSize()
	{
		std::cout << "Specilized Template for char " << std::endl;
		return N;
	}
};

//int main() {
//	Array<int, 5> intArry;
//	std::cout << "Size of int arry is " << intArry.GetSize() << std::endl;
//	Array<float,10> arr1;
//	std::cout << "Size of float arry is " << arr1.GetSize() << std::endl;
//	Array<char, 15> arr2;
//	std::cout << "Size of char arry is " << arr2.GetSize() << std::endl;
//	return 0;
//}