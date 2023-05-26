#include<iostream>

class DriveStrategy  // interface
{
public:
	virtual void Drive() = 0;
};

class NormalDriveStrategy : public DriveStrategy
{
	void Drive() override
	{
		std::cout << "Normal Drive Capacity " << std::endl;
	}
};

class SpecialDriveStrategy : public DriveStrategy
{
	void Drive() override
	{
		std::cout << "Special Drive Capacity " << std::endl;
	}
};

class XYZDriveStrategy : public DriveStrategy
{
	void Drive() override
	{
		std::cout << "XYZ Drive Capacity " << std::endl;
	}
};


class Vehicle
{
	DriveStrategy* driveStrategy;
public:
	Vehicle(DriveStrategy* driveStrategy) : driveStrategy{driveStrategy} {}

	void Drive()
	{
		driveStrategy->Drive();
	}
};

class SportsVehicle : public Vehicle
{
public:
	SportsVehicle() : Vehicle(new SpecialDriveStrategy()){}
};

class OffRoadVehicle : public Vehicle
{
public:
	OffRoadVehicle() : Vehicle(new SpecialDriveStrategy()) {}
};

class PassengerVehicle : public Vehicle
{
public:
	PassengerVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class GoodsVehicle : public Vehicle
{
public:
	GoodsVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

int main()
{
	Vehicle* sportsVehicle = new SportsVehicle();
	sportsVehicle->Drive(); // should print special capacity

	Vehicle* goodsVehicle = new GoodsVehicle();
	goodsVehicle->Drive(); // should print normal capacity
}