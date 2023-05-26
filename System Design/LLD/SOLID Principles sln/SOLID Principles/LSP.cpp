#include<iostream>
#include<vector>
// If B is a child A, then we should be able to replace the obj of A with obj of B without breaking the behaviour of programe.
// subclass should extend the capabilityof parent cls not narrow it down.

//class Bike
//{
//public:
//	virtual void TurnOnEngine() = 0;
//	virtual void Accelerate() = 0;
//};
//
//class MotorCycle : public Bike
//{
//	bool isEngineOn;
//	int speed;
//public:
//	void TurnOnEngine() override
//	{
//		isEngineOn = true;
//	}
//
//	void Accelerate() override
//	{
//		speed = speed + 10;
//	}
//};
//
//
//class BiCycle : public Bike
//{
//	void TurnOnEngine() override        // TurnonEngine throws exception. it narrow down the functionality of parent.
//	{
//		throw new NoEngineException();
//	}
//
//	void Accelerate() override
//	{
//		// Do something
//	}
//};





// Liskov Substitution Principle

class Vehicle
{
public:
	virtual int GetNumberOfWheels()
	{
		return 2;
	}

	virtual std::string EngineType()
	{
		return "BS6";
	}
};


class MotorCycle : public Vehicle
{

};

class Car : public Vehicle
{
	int GetNumberOfWheels() override
	{
		return 4;
	}
};


//int main()
//{
//	std::vector<Vehicle*> v;
//	v.push_back(new MotorCycle());
//	v.push_back(new Car());
//
//	for (auto obj : v)
//	{
//		std::cout << obj->EngineType().toString() << std::endl;  // here no problem child objs are substitutable for parent objs.
//	}
//
//
//}

// if i add bicycle

class BiCycle : public Vehicle
{
	std::string EngineType()
	{
		return NULL;
	}
};

int main()
{
	std::vector<Vehicle*> v;
	v.push_back(new MotorCycle());
	v.push_back(new Car());
	v.push_back(new BiCycle());

	for (auto obj : v)
	{
		std::cout << obj->EngineType().toString() << std::endl;  // here bicycle is not substitutable for parent. it throws null pointer exception.
		// to overcome this seperate methods into diff clses.
	}


}



//Solution for above problem
class Vehicle
{
public:
	// Place moste general method in parent clas
	virtual int GetNumberOfWheels()
	{
		return 2;
	}
};

class EngineVehicle : public Vehicle
{
public:
	virtual std::string EngineType()
	{
		return "BS6";
	}
};

class MotorCycle : public EngineVehicle
{

};

class Car : public EngineVehicle
{
	// override GetnumberofWheels()
};

class Bicycle : public Vehicle
{

};


int main()
{
	std::vector<Vehicle*> v;
	v.push_back(new MotorCycle());
	v.push_back(new Car());
	v.push_back(new BiCycle());

	for (auto obj : v)
	{
		std::cout << obj->GetNumberOfWheels()<< std::endl;  // here bicycle is substitutable for parent. to solve the problem of LSP , divide methods into diff clses.
	}


}