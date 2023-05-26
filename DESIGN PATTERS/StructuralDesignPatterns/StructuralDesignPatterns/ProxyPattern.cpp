#include <iostream>

class Subject
{
public:
    virtual void DoSomework() = 0;
};

class ConcreateSubject : public Subject
{
public:
    void DoSomework() override
    {
        std::cout << "Doing Something Action in ConcreateSubject";
    }
};

class Proxy : public Subject
{
private:
    Subject* obj;
public:
    void DoSomework() override
    {
        std::cout << "Proxy call happening" << std::endl;
        if (obj == nullptr)
        {
            obj = new ConcreateSubject();
        }
        obj->DoSomework();
    }
};

int main()
{
    std::cout << "Proxy Pattern\n";
    Proxy proxy;
    proxy.DoSomework();
}
