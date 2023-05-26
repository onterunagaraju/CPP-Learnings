#include <iostream>


class BasicCar
{
public:
    std::string ModelName;
    int Price;
    static int SetPrice()
    {
        int price = 0;
        int range = 300000;
        price = rand() % range + 200000;
        return price;
    }
    virtual BasicCar* Clone() = 0;
};

class Nano: public BasicCar
{
public:
    Nano(std::string model)
    {
        ModelName = model;
    }
    Nano(const Nano* obj)
    {
        this->ModelName = obj->ModelName;
    }
    BasicCar* Clone() override
    {
        return new Nano(*this);
    }
};

class Ford : public BasicCar
{
public:
    Ford(std::string model)
    {
        ModelName = model;
    }
    Ford(const Ford* obj)
    {
        this->ModelName = obj->ModelName;
    }
    BasicCar* Clone() override
    {
        return new Ford(*this);
    }
};

int main()
{
    // Base or Original Copy
    BasicCar* nano_base = new Nano("Green nano");
    nano_base->Price = 100000;

    BasicCar* ford_base = new Ford("Yello Ford");
    ford_base->Price = 500000;

    // i want to create a nano car , clone it from nano base car
    BasicCar* nanoCar = nano_base->Clone();
    nanoCar->Price = nano_base->Price + BasicCar::SetPrice();
    std::cout << "Car is " << nanoCar->ModelName << " Price is " << nanoCar->Price << std::endl;

    BasicCar* fordCar = ford_base->Clone();
    fordCar->Price = ford_base->Price + BasicCar::SetPrice();
    std::cout << "Car is " << fordCar->ModelName << " Price is " << fordCar->Price << std::endl;
}

