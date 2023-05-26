#include <iostream>



class Base {
public:
    Base() {
        std::cout << "Base Constructor, Obj created \n";
    }
    ~Base() {
        std::cout << "Base destructor, obj destroyed \n";
    }
};
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor, obj created \n";
    }
    ~Derived() {
        std::cout << "Derived Destructor , Obj destroyed \n";
    }
};

void divide(int x, int y) {
    if (y == 0)
        throw "Cant divide by zero";//'R'; //404 ;//"Cant divide by zero";
    std::cout << "division " << x / y << std::endl;
}

int main() {
    std::cout << "Hello World!" << std::endl;
    std::cout << "Before try \n";
    
    try {

        Derived d;
        divide(10, 1);
        //throw d;
        try {
            
            throw 20.5;
        }
        catch (double d) {
            std::cout << "partially handling \n";
            throw;
        }
    }
    catch (const char* exceptionMsg) {
        std::cout << "Exception occured " << exceptionMsg << std::endl;
    }
    catch (int exceptionMsg) {
        std::cout << "Exception occured " << exceptionMsg << std::endl;
    }
    catch (double d) {
        std::cout << "Remaining handling\n";
        //throw;
    }
    
    catch (const Derived& d)  {
        std::cout << "Caught Derived Exception" << std::endl;
    }
    catch (const Base& d) {
        std::cout << "Caught Base Exception" << std::endl;
    }
    catch (...) {
        std::cout << "Exception occured \n";
    }
    

       std::cout << "After catch (Will be executed) \n";
}