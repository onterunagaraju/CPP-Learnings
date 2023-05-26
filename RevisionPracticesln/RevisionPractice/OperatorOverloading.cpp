#include<iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y=0) : x{x},y{y} {}
	Point operator + (const Point& p)
	{
		Point temp;
		temp.x = x + p.x;
		temp.y = y + p.y;
		return temp;
	}
	Point operator - ()
	{
		return Point(-x, -y);
	}

	friend std::ostream& operator << (std::ostream& out, const Point& point);
	friend std::istream& operator >> (std::istream& input, Point& point);

	void Print()
	{
		std::cout << "X: " << x << " Y: " << y << std::endl;
	}
};

std::ostream& operator << (std::ostream& out, const Point& point)
{
	out << "X: " << point.x << " Y: " << point.y << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Point& point)
{
	std::cout << "Enter point cordinates seperated by space" << std::endl;
	in >> point.x >> point.y;
	return in;
}





//Overload subscript operator
// [],(),->,= should be non static member functions. should not be friend functions.
class Complex
{
	int arr[2]; // real at 0, img at 1 index
public:
	Complex(int real = 0, int img = 0) {
		arr[0] = real;
		arr[1] = img;
	}
	//Syntax
	int& operator[] (int pos)
	{
		if (pos == 0) return arr[0];
		else if (pos == 1) return arr[1];
		else {
			std::cout << "Index out of bounds case." << std::endl;
			exit(0);
		}
	}

	void Print()
	{
		std::cout << "Real: " << arr[0] << " Imginary: " << arr[1] << std::endl;
	}

};



//// = overloading
class Integer
{
	int* x;
public:
	Integer(int n = 0)
	{
		x = new int(n);
	}
	void Setx(int n)
	{
		*x = n;
	}
	void Print()
	{
		std::cout << "Integer value is " << *x << std::endl;
	}
	// what will happen if remove & in return type
	// if we do not return as referience then it will return as a copy which is temperory , so (obj1 = obj2) = obj3 in this type of situation
	// (a = b) = c becomes a = c and (a = b) returns a temporary obj, so, for a = c is like declaration and initialization so, it needs a copy constructor. so, it returns new obj instead of the same ref to obj.
	Integer& operator = (const Integer& rhs) // deep copy
	{
		if (this == &rhs)
			return *this;
		x = new int(*(rhs.x));
		return *this;
	}
};

// Overload typecasting (type conversion operator)

double DollartoRupeeExchangeRate()
{
	return 81.2;
}

class Rupee
{
	double rupee;
public:
	Rupee(double x = 0) : rupee{x} {}
	void Print()
	{
		std::cout << "rupees : " << rupee << std::endl;
	}
};

class Dollar
{
	double dollar;
public:
	Dollar(double d = 0) : dollar{d} {}
	void Print()
	{
		std::cout << "dollar : " << dollar << std::endl;
	}
	// conversion from dollar to rupee
	operator Rupee()
	{
		return Rupee(dollar * DollartoRupeeExchangeRate());
	}
};


int main()
{
	Point p(1, 2);
	Point p1(2, 3);
	Point p2 = p + p1;
	p.Print();
	p1.Print();
	p2.Print();
	p2 = -p;
	p2.Print();
	std::cout << "Overloading inserion and extraction operators " << std::endl;
	std::cin >> p;
	std::cout << p;


	Complex c(1, 2);
	c.Print();
	c[0] = 3;
	c[1] = 4;
	c.Print();

	// = overloading
	Integer i1(10);
	Integer i2;
	i2 = i1; // now i1 and i2 are 10
	Integer i3;
	i1.Setx(20); // now actually i1 is 20 and i2 is 10 it should be as like this. But both are 20 as shollow copy done here if we overload = then it will be 20 , 10;
	i1.Print();
	i2.Print();
	(i1 = i2) = i3;
	i1.Print();
	i2.Print();
	i3.Print();

	// type conversion
	Dollar d(10);
	Rupee r;
	r = d;
	r.Print();
	d.Print();
	return 0;
}