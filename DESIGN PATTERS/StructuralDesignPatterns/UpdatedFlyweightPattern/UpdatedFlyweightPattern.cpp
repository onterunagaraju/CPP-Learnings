#include <iostream>
#include<map>
#include<thread>
#include<cstdlib>

class IRobot
{
public:
    virtual void Print() = 0;
};

class Robot : public IRobot
{
    std::string robotType;
public:
    std::string colorOfRobot;
    Robot(std::string robotType)
    {
        this->robotType = robotType;
    }
    void SetColor(std::string colorOfRobot)
    {
        this->colorOfRobot = colorOfRobot;
    }
    void Print() override
    {
        std::cout << "This is a " << robotType << " type robot with " << colorOfRobot << " color" << std::endl;
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
                std::cout << " We don't have Small robots , so we are creating new one" << std::endl;
                robo = new Robot(robotType);
                shapes.insert({ robotType, robo });
            }
            else
            {
                std::cout << " We don't have Large robots , so we are creating new one" << std::endl;
                robo = new Robot(robotType);
                shapes.insert({ robotType, robo });
            }
        }
        return robo;
    }
};

std::string GetRandomColor()
{
    int random = rand() % 100;
    if (random % 2)
    {
        return "green";
    }
    return "red";
}

int main()
{
    std::cout << "Updated Flyweight Pattern!\n";
    RobotFactory* roboFactory = new RobotFactory();
    Robot* robo = nullptr;
    for (int i = 0; i < 3; i++)
    {
        robo = (Robot*) roboFactory->GetRobotFromFactory("small");
        /* we are creating small robots*/
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        robo->SetColor(GetRandomColor());
        robo->Print();
    }
    for (int i = 0; i < 3; i++)
    {
        robo = (Robot*)roboFactory->GetRobotFromFactory("large");
        /* we are creating small robots*/
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        robo->SetColor(GetRandomColor());
        robo->Print();
    }

    int numberOfObjsCreated = roboFactory->TotalObjectsCreated();
    std::cout << "Number of distinct objs created is " << numberOfObjsCreated << std::endl;

}
