#include <iostream>
#include<map>
#include<string>


class IRobot
{
public:
    virtual void Print() = 0;
};

class SmallRobot : public IRobot
{
public:
    void Print() override
    {
        std::cout << "This is small robot" << std::endl;
    }
};

class LargeRobot : public IRobot
{
public:
    void Print() override
    {
        std::cout << "This is large robot" << std::endl;
    }
};

class RobotFactory
{
    std::map<std::string, IRobot*> shapes;
public:
    int TotalObjectsCreated()
    {
        return shapes.size();
    }
    IRobot* GetRobotFromFactory(std::string robotType)
    {
        IRobot* robo = nullptr;
        if (shapes.find(robotType) != shapes.end())
        {
            robo = shapes[robotType];
        }
        else
        {
            if (robotType == "small")
            {
                robo = new SmallRobot();
                shapes.insert(std::make_pair("small", robo));
            }
            else
            {
                robo = new LargeRobot();
                shapes.insert(std::make_pair("large", robo));
            }
            
        }
        return robo;
    }
};



int main()
{
    std::cout << "Flyweight Pattern Demo!\n";
    RobotFactory* roboFactory = new RobotFactory();
    IRobot* smallRobot = roboFactory->GetRobotFromFactory("small");
    smallRobot->Print();
    /* now are trying to get some more small robotos but we need not create new robots as small robot
    is already created*/
    for (int i = 0; i < 2; i++)
    {
        smallRobot = roboFactory->GetRobotFromFactory("small");
        smallRobot->Print();
    }
    int numberOfInstancesCreated = roboFactory->TotalObjectsCreated();
    std::cout << "Total number of distinct robots created is " << numberOfInstancesCreated << std::endl;
    /*we are trying to create Large robots now, Robot obj will create for the first time but from second time onwards
    robot obj will not created*/
    IRobot* largeRobot = roboFactory->GetRobotFromFactory("large");
    largeRobot->Print();
    for (int i = 0; i < 5; i++)
    {
        largeRobot = roboFactory->GetRobotFromFactory("large");
        largeRobot->Print();
    }
    numberOfInstancesCreated = roboFactory->TotalObjectsCreated();
    std::cout << "Total number of distinct robots created is " << numberOfInstancesCreated << std::endl;
}
