// DecoratorDPPizzaBilling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class BasePizza
{
public:
    virtual int Cost() = 0;
};

class FormHousePizza : public BasePizza
{
public:
    int Cost() override
    {
        return 200;
    }
};

class VegDelightPizza : public BasePizza
{
    int Cost() override
    {
        return 120;
    }
};

class MargheritaPizza : public BasePizza
{
public:
    int Cost() override
    {
        return 100;
    }
};



class ToppingsDecorator : public BasePizza
{

};

class ExtraCheese : public ToppingsDecorator
{
    BasePizza* pizza;
public:
    ExtraCheese(BasePizza* pizza) : pizza{ pizza } {}

    int Cost() override
    {
        return pizza->Cost() + 10;
    }
};

class ExtraMushRooms : public ToppingsDecorator
{
    BasePizza* pizza;
public:
    ExtraMushRooms(BasePizza* pizza) : pizza{ pizza } {}

    int Cost() override
    {
        return pizza->Cost() + 15;
    }
};

int main()
{
    // if we need Baseic VegDelight Pizza
    BasePizza* vegPizza = new VegDelightPizza();
    std::cout << "Basic Veg Pizza costs : " << vegPizza->Cost() << std::endl;
    // Now if we want to decorate with extra cheese
    BasePizza* vegPizzaWithExtraCheese = new ExtraCheese(vegPizza);
    std::cout << "Veg Pizza with extra cheese costs : " << vegPizzaWithExtraCheese->Cost() << std::endl;

    // if we need margharita pizza with extra cheese and extra mushrooms
    BasePizza* margharitaPizzaWithExtraCheeExtraMush = new ExtraMushRooms(new ExtraCheese(new MargheritaPizza()));
    std::cout << "Margharita Pizza with extra cheese and extra mushrooms costs : " << margharitaPizzaWithExtraCheeExtraMush->Cost() << std::endl;
}
