#include<iostream>
#include<string>

class Person
{
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name{ name }, age{ age } {}

	void SetProperties(std::string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void Display()
	{
		std::cout << "Name " << name << std::endl;
		std::cout << "Age " << age << std::endl;
	}
};

//int main()
//{
//	Person p("Nagaraju", 22);
//	p.Display();
//
//	p.SetProperties("Raju", 23);
//	p.Display();
//	return 0;
//}