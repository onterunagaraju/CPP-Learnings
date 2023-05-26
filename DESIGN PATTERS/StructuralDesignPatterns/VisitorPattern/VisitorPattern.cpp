#include <iostream>

class IOriginalInterface
{
public:
    virtual void Accept(IVisitor* visitor) = 0;
};


class MyClass : public IOriginalInterface
{
private:
    int myInt = 5; // Initial value
public:
    void SetInt(int value)
    {
        myInt = value;
    }
    int GetInt()
    {
        return myInt;
    }
    void Accept(IVisitor* visitor) override
    {
        std::cout << "Initial value of integer is " << myInt << std::endl;
        visitor->Visit(this);
        std::cout << "Value of integer now is " << myInt << std::endl;
    }
};

class IVisitor
{
public:
    virtual void Visit(MyClass* myclsElement) = 0;
};

class Visitor : public IVisitor
{
public:
    void Visit(MyClass* myclsElement) override
    {
        std::cout << "Visitor pattern is trying to chage integer value" << std::endl;
        myclsElement->SetInt(100);
        std::cout << "Exiting from visitor pattern" << std::endl;
    }
};

int main()
{
    std::cout << "Visitor Pattern Demo!\n";
    IVisitor* visitor = new Visitor();
    MyClass* myClass = new MyClass();
    myClass->Accept(visitor);
}

