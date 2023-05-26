#include<iostream>
#include<string>

class Person
{
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name{name}, age{age} {}

	void SetName(std::string name)
	{
		this->name = name;
	}
	std::string GetName()
	{
		return name;
	}

	void SetAge(int age)
	{
		this->age = age;
	}
	int GetAge()
	{
		return age;
	}
};

//int main()
//{
//	Person p("Nagaraju", 22);
//	std::cout << "Name " << p.GetName() << std::endl;
//	std::cout << "Age " << p.GetAge() << std::endl;
//	p.SetName("Raju");
//	p.SetAge(23);
//	std::cout << "Name " << p.GetName() << std::endl;
//	std::cout << "Age " << p.GetAge() << std::endl;
//	return 0;
//}