#include<iostream>

//this without using strategy design pattern

class Vehicle
{
public:
	virtual void Drive()
	{
		std::cout << "Normal Drive Capability" << std::endl;
	}
};

class SportsVehicle : public Vehicle
{
public:
	virtual void Drive() override
	{
		// different drive logic different from parent
		std::cout << "Special Drive Capability" << std::endl;
	}
};

class PassangerVehicle : public Vehicle
{
	// Same as parent
};

class OffRoadVehicle : public Vehicle
{
public:
	virtual void Drive() override
	{
		// different drive logic
		std::cout << "Special Drive Capability" << std::endl;
	}
};

class GoodsVehicle : public Vehicle
{
	// Same as parent;
};

// here Sports and Offroad vehicles have special capability diff from parent and they are redundant. to reduce Code redundancy use Strategy DP.
