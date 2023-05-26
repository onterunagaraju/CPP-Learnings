#include<iostream>

class String
{
	int _size;
	char* _data;
public:
	String(const char* data) // parametrized constructor
	{
		std::cout << "Created, Parametrized constructor " << std::endl;
		_size = strlen(data);
		_data = new char[_size];
		memcpy(_data, data, _size);
	}

	//String(const String& str) // Shallow Copy Constructor
	//{
	//	std::cout << "shallow copy " << std::endl;
	//	_size = str._size;
	//	_data = str._data;
	//}

	String(const String& str) // Deep Copy Constructor
	{
		std::cout << "Depp copy " << std::endl;
		_size = str._size;
		_data = new char[_size];
		memcpy(_data, str._data, _size);
	}

	String(String&& str) noexcept	// Move Constructor
	{
		std::cout << "Move Constructor " << std::endl;
		_size = str._size;
		_data = str._data;
		str._data = nullptr;	
	}

	String& operator = (const String& str) // Copy Assignment Operator
	{
		std::cout << "Copy Assignment operator " << std::endl;
		if (this == &str)
			return *this;
		_size = str._size;
		_data = new char[_size];
		memcpy(_data, str._data, _size);
		return *this;
	}

	String& operator= (String&& str) noexcept // Move assignment operator
	{
		std::cout << "Move assignement operator" << std::endl;
		if (this == &str)
			return *this;
		_size = str._size;
		_data = str._data;
		str._data = nullptr;
		return *this;
	}

	~String()
	{
		std::cout << "Destroyed " << std::endl;
	}

	void print()
	{
		for (size_t i = 0; i < _size; i++)
			std::cout << _data[i];
		std::cout << std::endl;
	}

};

//int main()
//{
//	String str("Hello"); //parameterized
//	String str1 = "World"; // parametrized
//	String str2(str); // copy
//	String str3 = str; // copy
//	str3 = str1; // assignment copy operator
//	String str4(std::move(str)); // move constructor
//	String str5(std::move(String("HelloWorld"))); //move Constructor
//
//	str3 = std::move(str5); // assignment move operator
//	return 0;
//}