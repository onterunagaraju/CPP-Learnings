#include <iostream>

class IAnimal
{
public:
    virtual void Speak() = 0;
    virtual void Action() = 0;
};

class Dog : public IAnimal
{
public:
    void Speak() override
    {
        std::cout << "Dog says Bow-Bow" << std::endl;
    }
    void Action() override
    {
        std::cout << "Dog Prefers Barking" << std::endl;
    }
};

class Tiger : public IAnimal
{
public:
    void Speak() override
    {
        std::cout << "Tiger says Halum.." << std::endl;
    }
    void Action() override
    {
        std::cout << "Tiger Prefers Hunting" << std::endl;
    }
};


class IAnimalFactory
{
public:
    virtual IAnimal* CreateAnimal() = 0;
};

class DogFactory : public IAnimalFactory
{
public:
    IAnimal* CreateAnimal() override
    {
        return new Dog();
    }
};

class TigerFactory : public IAnimalFactory
{
public:
    IAnimal* CreateAnimal() override
    {
        return new Tiger();
    }
};

int main()
{
    std::cout << "Factory Method Pattern!\n";
    IAnimalFactory* tigerFactory = new TigerFactory();
    IAnimal* tiger = tigerFactory->CreateAnimal();
    tiger->Action();
    tiger->Speak();

    IAnimalFactory* dogFactory = new DogFactory();
    IAnimal* dog = dogFactory->CreateAnimal();
    dog->Action();
    dog->Speak();
}

