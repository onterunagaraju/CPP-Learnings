#include<iostream>

//class RestaurentEmployee  // interface
//{
//public:
//	virtual void TakeOrder() = 0;
//	virtual void ServeCustomers() = 0;
//	virtual void CookFood() = 0;
//  virtual void DecideMenu() = 0;
//};
//
//
//class Waiter : public RestaurentEmployee
//{
//	void TakeOrder() override
//	{
//		// Taking the order from customers
//	}
//
//	void ServeCustomers() override
//	{
//		// Serving to customers
//	}
//
//	void CookFood() override
//	{
//		throe new NotApplicableException();  // Not the waiter job but forfully implemented
//	}
//
//  void DecideMenu() override
//	{
//		throe new NotApplicableException();  // Not the waiter job but forfully implemented
//	}
//	//so seggregate the interfaces
//};



// Interface Seggregation

class WaiterInterface
{
public:
	virtual void TakeOrder() = 0;
	virtual void ServeCustomers() = 0;
};

class ChefInterface
{
public:
	virtual void CookFood() = 0;
	virtual void DecideMenu() = 0;
};

class Waiter : public WaiterInterface
{
	void TakeOrder() override
	{
		// Takes order
	}

	void ServeCustomers() override
	{
		// Serves customers
	}
};

class Chef : public ChefInterface
{
	void CookFood() override
	{
		// Cooks food
	}

	void DecideMenu() override
	{
		//Decides the menu
	}
};