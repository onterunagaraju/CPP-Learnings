#include<iostream>

class Marker
{
public:
	std::string name;
	std::string color;
	int price;
public:
	Marker(std::string name, std::string color, int price) : name{name}, color{color}, price{price} {}
};


class Invoice
{
	Marker marker;
	int quantity;
public:
	Invoice(Marker marker, int quantity) : marker{marker}, quantity{quantity} {}

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
	InvoicePrinter(Invoice invoice) : invoice{invoice} {}

	void Print()
	{
		// Print the invoice
	}
};


class InvoiceDao
{
	Invoice invoice;
public:
	InvoiceDao(Invoice invoice) : invoice{invoice} {}

	void SaveToDb()
	{
		// Save the invoice to DB
	}
};

