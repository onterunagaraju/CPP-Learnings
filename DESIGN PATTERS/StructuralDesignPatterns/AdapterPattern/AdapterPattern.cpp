#include <iostream>


class Rectangle
{
public:
    int length;
    int breadth;
};

class Triangle
{
public:
    int base;
    int height;
    Triangle(int _base, int _height)
    {
        base = _base;
        height = _height;
    }
};

class Caluculator
{
public:
    int GetArea(Rectangle* rect)
    {
        return rect->breadth * rect->length;
    }
};

class CaluculatorAdapter
{
public:
    int GetArea(Triangle* tri)
    {
        Rectangle* rect = new Rectangle();
        rect->length = 0.5 * tri->base;
        rect->breadth = tri->height;
        Caluculator* calc = new Caluculator();
        return calc->GetArea(rect);
    }
};

int main()
{
    std::cout << "Adapter Pattern Demo!\n";
    Triangle* tri = new Triangle(20, 10);
    CaluculatorAdapter* adapter = new CaluculatorAdapter();
    // Getting area of triangle using CaluculatorAdaper(which converts triangle to rectangle) from Caluculator GETAREA which get the area of rectangle 
    std::cout << "Area of Triangle is " << adapter->GetArea(tri) << std::endl;
}

