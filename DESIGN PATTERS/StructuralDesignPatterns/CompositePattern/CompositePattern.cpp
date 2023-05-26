#include <iostream>
#include<vector>

class IEmployee
{
public:
    virtual void PrintStructures() = 0;
};

class Employee : public IEmployee
{
    std::string name;
    std::string dept;
public:
    Employee(std::string name, std::string dept)
    {
        this->name = name;
        this->dept = dept;
    }
    void PrintStructures() override
    {
        std::cout << "\t\t" << name << " works in " << dept << std::endl;
    }
};

class CompositeEmployee : public IEmployee
{
    std::string name;
    std::string dept;
    //container for child objects
    std::vector<IEmployee*> controls;
public:
    CompositeEmployee(std::string name, std::string dept)
    {
        this->name = name;
        this->dept = dept;
    }
    void Add(IEmployee* employee)
    {
        controls.push_back(employee);
    }
    void Remove(IEmployee* employee)
    {
        controls.erase(find(controls.begin(), controls.end(), employee));
    }
    void PrintStructures() override
    {
        std::cout << "\t" << name << " Works in " << dept << std::endl;
        for (IEmployee* employee : controls)
        {
            employee->PrintStructures();
        }
    }
};


int main()
{
    std::cout << "Composite Pattern Demo!\n";
    //Principal of the campus
    CompositeEmployee* principal = new CompositeEmployee("Dr.S.Som (Principal)", "Planning - Supervising - Managing");
    // College has two departments. 1)maths 2)CS
    CompositeEmployee* hodMaths = new CompositeEmployee("Mrs.S.Das(HOD-Maths)", "Maths");
    CompositeEmployee* hodCompSc = new CompositeEmployee("Mr. V.Sarcar(HOD-CSE)", "Computer Sc.");
    // 2 teachers works in maths dept and reports to maths hod
    Employee* mathTeacher1 = new Employee("Math Teacher-1", "Maths");
    Employee* mathTeacher2 = new Employee("Math Teacher-2", "Maths");
    hodMaths->Add(mathTeacher1);
    hodMaths->Add(mathTeacher2);

    // 3 teachers works in CS and reports to CompSc hod
    Employee* compScTeacher1 = new Employee("CompSc Teacher-1", "CompSc");
    Employee* compScTeacher2 = new Employee("CompSc Teacher-2", "CompSc");
    Employee* compScTeacher3 = new Employee("CompSc Teacher-3", "CompSc");
    hodCompSc->Add(compScTeacher1);
    hodCompSc->Add(compScTeacher2);
    hodCompSc->Add(compScTeacher3);

    // Principal is top of the college and hodMaths and hodCompSc reports to Principal
    principal->Add(hodMaths);
    principal->Add(hodCompSc);

    std::cout << "Structure of Principal Obj" << std::endl;
    // Prints the complete structure
    principal->PrintStructures();

    std::cout << "Structure of HodMaths" << std::endl;
    // Prints Hod Maths Structure
    hodMaths->PrintStructures();

    std::cout << "Structure of HodCompSc" << std::endl;
    // Prints Hod CompSc Structure
    hodCompSc->PrintStructures();


    //Testing Leaf Node obj
    mathTeacher1->PrintStructures();

    // If one employee from CompSc left
    hodCompSc->Remove(compScTeacher3);
    std::cout << "After one employee left from organization, the Structure is looks like" << std::endl;
    principal->PrintStructures();

}

