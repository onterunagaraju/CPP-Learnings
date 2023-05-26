#include<iostream>

class Marker
{
public:
	std::string name;
	std::string color;
	int price;
public:
	Marker(std::string name, std::string color, int price) : name{ name }, color{ color }, price{ price } {}
};


class Invoice
{
	Marker marker;
	int quantity;
public:
	Invoice(Marker marker, int quantity) : marker{ marker }, quantity{ quantity } {}

	int CalculateTotal()
	{
		int price = marker.price * this->quantity;
		return price;
	}


	// the below two methods voilating SRP 
	// 
	//void PrintInvoice()
	//{
	//	//Printing Invoice
	//}


	//void SaveToDb()
	//{
	//	//Saveing to Db
	//}
};


class InvoicePrinter
{
	Invoice invoice;
public:
	InvoicePrinter(Invoice invoice) : invoice{ invoice } {}

	void Print()
	{
		// Print the invoice
	}
};


//class InvoiceDao
//{
//	Invoice invoice;
//public:
//	InvoiceDao(Invoice invoice) : invoice{ invoice } {}
//
//	void SaveToDb()
//	{
//		// Save the invoice to DB
//	}
//};



// Here for the above cls, if i want to save the invoice to file then i need to change the Invoice DAO class . i.e, it is voilating OCP.
//class InvoiceDao
//{
//	Invoice invoice;
//public:
//	InvoiceDao(Invoice invoice) : invoice{ invoice } {}
//
//	void SaveToDb()
//	{
//		// Save the invoice to DB
//	}
//
//	void SaveToFile()
//	{
//		// save the invoice to File
//	}
//};
// 
// 
// To satisfy OCP., instead of modifying just extend the exsting cls.

class InvoiceDao     // interface
{
public:
	virtual void Save(Invoice invoice) = 0;
};

class DataBaseInvoicDao : public InvoiceDao
{
public:
	void Save(Invoice invoice) override
	{
		// save the invoice to DB;
	}
};

class FileInvoiceDao : public InvoiceDao
{
public:
	void Save(Invoice invoice) override
	{
		// save the invoice to File;
	}
};

// Now it satisfys the OCP
