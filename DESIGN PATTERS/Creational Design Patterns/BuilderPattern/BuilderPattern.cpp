#include <iostream>
#include<memory>


// Pizza is the product
class Pizza
{
private:
    std::string _dough;
    std::string _sauce;
    std::string _topping;
public:
    void SetDough(const std::string& dough)
    {
        _dough = dough;
    }
    void SetSauce(const std::string& sauce)
    {
        _sauce = sauce;
    }
    void SetTopping(const std::string& topping)
    {
        _topping = topping;
    }
    void Open() const
    {
        std::cout << "The Pizza have " << _dough << " dough " << _sauce << " sauce " << _topping << " topping.\n";
    }
};


// This is the Abstract Builder
class PizzaBuilder
{
protected:
    std::unique_ptr<Pizza> _pizza;
public:
    virtual ~PizzaBuilder() = default;
    void CreateNewPizza()
    {
        _pizza = std::make_unique<Pizza>();
    }
    Pizza* GetPizza()
    {
        return _pizza.release();
    }
    virtual void BuildDough() = 0;
    virtual void BuildSauce() = 0;
    virtual void BuildTopping() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    ~HawaiianPizzaBuilder() = default;
    void BuildDough() override
    {
        _pizza->SetDough("HawaiianPizza dough");
    }
    void BuildSauce() override
    {
        _pizza->SetSauce("HawaiianPizza sauce");
    }
    void BuildTopping() override
    {
        _pizza->SetTopping("HawaiianPizza topping");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    ~SpicyPizzaBuilder() = default;
    void BuildDough() override
    {
        _pizza->SetDough("SpicyPizza dough");
    }
    void BuildSauce() override
    {
        _pizza->SetSauce("SpicyPizza Sauce");
    }
    void BuildTopping() override
    {
        _pizza->SetTopping("SpicyPizza topping");
    }
};

class Cook
{
private:
    PizzaBuilder* _pizzaBuilder;
public:
    void OpenPizza() const
    {
        _pizzaBuilder->GetPizza()->Open();
    }
    void CreatePizza(PizzaBuilder* pizzaBuilder)
    {
        _pizzaBuilder = pizzaBuilder;
        _pizzaBuilder->CreateNewPizza();
        _pizzaBuilder->BuildDough();
        _pizzaBuilder->BuildSauce();
        _pizzaBuilder->BuildTopping();
    }
};

int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianPizza;
    cook.CreatePizza(&hawaiianPizza);
    cook.OpenPizza();

    SpicyPizzaBuilder spicyPizza;
    cook.CreatePizza(&spicyPizza);
    cook.OpenPizza();
}

