// FactoryPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Shape
{
public:
    virtual void Draw() = 0;
};

class Circle : public Shape
{
public:
    void Draw() override
    {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape
{
public:
    void Draw() override
    {
        std::cout << "Drawing Square" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void Draw() override
    {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

class ShapeFactory
{
public:
    Shape* GetShape(std::string input)
    {
        if (input == "circle")
        {
            return new Circle();
        }
        else if (input == "square")
        {
            return new Square();
        }
        else
        {
            return new Rectangle();
        }
    }
};

int main()
{
    ShapeFactory* factory = new ShapeFactory();
    Shape* circle = factory->GetShape("circle");
    circle->Draw();
}

