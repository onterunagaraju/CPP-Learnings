#include<iostream>

class String
{
	int _size;
	char* _data;
public:
	String(const char* str)
	{
		std::cout << "Created, Parametrized Constructor " << std::endl;
		_size = strlen(str);
		_data = new char[_size];
		memcpy(_data, str, _size);
	}

	//String(const String& str) // Shallow copy
	//{
	//	std::cout << "Shallow copy constructor " << std::endl;
	//	_size = str._size;
	//	_data = str._data;
	//}

	String(const String& str) // deep copy
	{
		std::cout << "Deep copy constructor " << std::endl;
		_size = str._size;
		_data = new char[_size];
		memcpy(_data, str._data, _size);
	}

	String(String&& str) // move Constructor
	{
		std::cout << "Move constructor " << std::endl;
		_size = str._size;
		_data = str._data;
		str._data = nullptr;
	}

	String& operator = (const String& str)
	{
		std::cout << "Copy assignment Operator " << std::endl;
		if (this == &str)
			return *this;
		_size = str._size;
		delete[] _data;
		_data = new char[_size];
		memcpy(_data, str._data, _size);
		return *this;
	}

	String& operator=(String&& str)
	{
		std::cout << "Move Assignment Opearator " << std::endl;
		_size = str._size;
		_data = str._data;
		str._data = nullptr;
		return *this;
	}

	~String()
	{
		std::cout << "Destroyed " << std::endl;
		delete[] _data;
	}

	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			std::cout << _data[i];
		}
		std::cout << std::endl;
	}
};

//int main()
//{
//	String str("Hello");
//	String str1 = str;
//	String str2(str);
//	String str3 = "World";
//	String str4(std::move(String("Move")));
//	str3 = str;
//	str3 = std::move(str);
//	return 0;
//}