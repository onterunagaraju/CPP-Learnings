#include <iostream>


class Component
{
public:
   virtual void MakeHouse() = 0;
};

class ConcreateComponent : public Component
{
public:
    virtual void MakeHouse() override
    {
        std::cout << "Original House is created. It is closed for Modification"<< std::endl;
    }
};

class AbstractDecorator : public Component
{
protected:
    Component* com;
public:
    void SetTheComponent(Component* c)
    {
        com = c;
    }
    virtual void MakeHouse() override
    {
        if (com != nullptr)
        {
            com->MakeHouse(); // Delegating the task
        }
    }
};

class ConcreateDecoratorEx1 : public AbstractDecorator
{
private:
    void AddFloor()
    {
        std::cout << "I am making additional floor on top of it." << std::endl;
    }
public:
    virtual void MakeHouse() override 
    {
        AbstractDecorator::MakeHouse();
        std::cout << "Using Decorator" << std::endl;
        // decorating now
        AddFloor();
    }
};


class ConcreateDecoratorEx2 : public AbstractDecorator
{
private:
    void PaintTheHouse()
    {
        std::cout << "I am painting the house." << std::endl;
    }
public:
    virtual void MakeHouse() override
    {
        AbstractDecorator::MakeHouse();
        std::cout << "Using decorator" << std::endl;
        //decorate now
        PaintTheHouse();
    }
};

int main()
{
    std::cout << "Decorator Pattern!\n";
    ConcreateComponent* cc = new ConcreateComponent();
    ConcreateDecoratorEx1* decorator1 = new ConcreateDecoratorEx1();
    decorator1->SetTheComponent(cc);
    decorator1->MakeHouse();

    ConcreateDecoratorEx2* decorator2 = new ConcreateDecoratorEx2();
    decorator2->SetTheComponent(decorator1);
    decorator2->MakeHouse();
}

