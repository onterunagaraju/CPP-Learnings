#include <iostream>


class IAnimal
{
public:
    virtual void Action() = 0;
    virtual void Speak() = 0;
};

class Dog : public IAnimal
{
public:
    void Action() override
    {
        std::cout << "Dog Prefers Barking" << std::endl;;
    }
    void Speak() override
    {
        std::cout << "Dog says: Bow-Bow" << std::endl;
    }
};

class Tiger : public IAnimal
{
public:
    void Action() override
    {
        std::cout << "Tiger Prefers Hunting" << std::endl;
    }
    void Speak() override
    {
        std::cout << "Tiger says: Halun." << std::endl;
    }
};


class IFactory
{
public:
    virtual IAnimal* CreateAnimal(const std::string& animal) = 0;
};

class AnimalFactory : public IFactory
{
public:
    IAnimal* CreateAnimal(const std::string& animal) override
    {
        if (animal == "Dog")
        {
            return new Dog();
        }
        else 
        {
            return new Tiger();
        }
    }
};

int main()
{
    IFactory* factory = new AnimalFactory();
    IAnimal* dog = factory->CreateAnimal("Dog");
    dog->Action();
    dog->Speak();

    IAnimal* tiger = factory->CreateAnimal("tiger");
    tiger->Action();
    tiger->Speak();

}

