#include <iostream>

class IState
{
public:
    virtual void MoveState() = 0;
};

class OnState : public IState
{
public:
    void MoveState() override
    {
        std::cout << "On State" << std::endl;
    }
};

class OffState : public IState
{
public:
    void MoveState() override
    {
        std::cout << "Off State" << std::endl;
    }
};

class ElectronicGoods
{
protected:
    IState* state;
public:
    IState* GetState()
    {
        return state;
    }
    void SetState(IState* _state)
    {
        state = _state;
    }
    virtual void MoveToCurrentState() = 0;
};

class Telivision : public ElectronicGoods
{
public:
    void MoveToCurrentState() override
    {
        std::cout << "Television is working at ";
        state->MoveState();
    }
};

class VCD : public ElectronicGoods
{
public:
    void MoveToCurrentState() override
    {
        std::cout << "VCD is working at ";
        state->MoveState();
    }
};

int main()
{
    std::cout << "Bridge Pattern Demo!\n";
    std::cout << "Dealing with Telivision\n";
    ElectronicGoods* eItem = new Telivision();
    IState* presetState = new OnState();
    eItem->SetState(presetState);
    eItem->MoveToCurrentState();
    // Veriying Off State
    presetState = new OffState();
    eItem->SetState(presetState);
    eItem->MoveToCurrentState();

    std::cout << "\n\n dealing with VCD\n";
    eItem = new VCD();
    presetState = new OnState();
    eItem->SetState(presetState);
    eItem->MoveToCurrentState();
    presetState = new OffState();
    eItem->SetState(presetState);
    eItem->MoveToCurrentState();

}

