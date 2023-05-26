#include <iostream>


class RobotBody
{
public:
    void CreateHands()
    {
        std::cout << "Hands manufactured" << std::endl;
    }
    void CreateRemainingParts()
    {
        std::cout << "Remaining parts (other than hands) are created" << std::endl;
    }
    void DestroyHands()
    {
        std::cout << "The robot's hands are destroyed" << std::endl;
    }
    void DestroyRemainingParts()
    {
        std::cout << "The robot's remaining parts are destroyed" << std::endl;
    }
};

class RobotColor
{
public:
    void SetDefaultColor()
    {
        std::cout << "This is steel color robot." << std::endl;
    }
    void SetGreenColor()
    {
        std::cout << "This is a green color robot." << std::endl;
    }
};

class RobotHands
{
public:
    void SetMilanoHands()
    {
        std::cout << "The robot will have EH1 Milano hands" << std::endl;
    }
    void SetRobonautHands()
    {
        std::cout << "The robot will have Robonaut hands" << std::endl;
    }
    void ResetMilanoHands()
    {
        std::cout << "EH1 Milano hands are about to be destroyed" << std::endl;
    }
    void ResetRobonautHands()
    {
        std::cout << "Robonaut hands are about to be destroyed" << std::endl;
    }
};

class RobotFacade
{
private:
    RobotBody* rb;
    RobotColor* rc;
    RobotHands* rh;
public:
    RobotFacade()
    {
        rb = new RobotBody();
        rc = new RobotColor();
        rh = new RobotHands();
    }
    void ConstructMilanoRobot()
    {
        std::cout << "Creation of a Milano Robot Start" << std::endl;
        rc->SetDefaultColor();
        rh->SetMilanoHands();
        rb->CreateHands();
        rb->CreateRemainingParts();
        std::cout << "Milano Robot Creation End" << std::endl;
    }
    void ConstructRobonautRobot()
    {
        std::cout << "Creation of a Robonaut Robot Start" << std::endl;
        rc->SetGreenColor();
        rh->SetRobonautHands();
        rb->CreateHands();
        rb->CreateRemainingParts();
        std::cout << "Robonaut Robot Creation End" << std::endl << std::endl;
    }
    void DestroyMilanoRobot()
    {
        std::cout << "Milano Robot's destruction process is started" << std::endl;
        rh->ResetMilanoHands();
        rb->DestroyHands();
        rb->DestroyRemainingParts();
        std::cout << "Milano Robot's destruction process is over" << std::endl;
    }
    void DestroyRobonautRobot()
    {
        std::cout << "Robonaut Robot's destruction process is started" << std::endl;
        rh->ResetRobonautHands();
        rb->DestroyHands();
        rb->DestroyRemainingParts();
        std::cout << "Robonaut Robot's destruction process is over" << std::endl << std::endl;
    }
};

int main()
{
    std::cout << "FACADE PATTERN DEMO!\n";
    // create robots
    RobotFacade* rf1 = new RobotFacade();
    rf1->ConstructMilanoRobot();

    RobotFacade* rf2 = new RobotFacade();
    rf2->ConstructRobonautRobot();

    //Destroy Robots
    rf1->DestroyMilanoRobot();
    rf2->DestroyRobonautRobot();
    return 0;
}



