#include <iostream>

class IDog
{
public:
    virtual void Speak() = 0;
    virtual void Action() = 0;
};

class ITiger
{
public:
    virtual void Speak() = 0;
    virtual void Action() = 0;
};

class WildDog : public IDog
{
public:
    void Speak() override
    {
        std::cout << "Wild Dog says: Bow-Wow." << std::endl;
    }
    void Action() override
    {
        std::cout << "Wild Dogs prefer to roam freely in jungles." << std::endl;
    }
};

class WildTiger :public ITiger
{
public:
    void Speak() override
    {
        std::cout << "Wild Tiger says: Halum." << std::endl;
    }
    void Action() override
    {
        std::cout << "Wild Tigers prefer hunting in jungles." << std::endl;
    }
};

class PetDog : public IDog
{
public:
    void Speak() override
    {
        std::cout << "Pet Dog says: Bow-Wow." << std::endl;
    }
    void Action() override
    {
        std::cout << "Pet Dogs prefer to stay at home." << std::endl;
    }
};

class PetTiger : public ITiger
{
public:
    void Speak() override
    {
        std::cout << "Pet Tiger says : Halum." << std::endl;
    }
    void Action() override
    {
        std::cout << "Pet Tigers play in an animal circus." << std::endl;
    }
};


class IAnimalFactory
{
public:
    virtual IDog* GetDog() = 0;
    virtual ITiger* GetTiger() = 0;
};

class WildAnimalFactory : public IAnimalFactory
{
public:
    IDog* GetDog() override
    {
        return new WildDog();
    }
    ITiger* GetTiger() override
    {
        return new WildTiger();
    }
};

class PetAnimalFactory : public IAnimalFactory
{
    IDog* GetDog() override
    {
        return new PetDog();
    }
    ITiger* GetTiger() override
    {
        return new PetTiger();
    }
};



int main()
{
    std::cout << "Abstract Factory Pattern World!\n";

    IAnimalFactory* animalFactory = new WildAnimalFactory();
    IDog* wildDog = animalFactory->GetDog();
    ITiger* wildTiger = animalFactory->GetTiger();
    wildDog->Action();
    wildDog->Speak();
    wildTiger->Action();
    wildTiger->Speak();

    IAnimalFactory* petAnimalFactory = new PetAnimalFactory();
    IDog* petDog = petAnimalFactory->GetDog();
    ITiger* petTiger = petAnimalFactory->GetTiger();
    petDog->Action();
    petDog->Speak();
    petTiger->Action();
    petTiger->Speak();
}
