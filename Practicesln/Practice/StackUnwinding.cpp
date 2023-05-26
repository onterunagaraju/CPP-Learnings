#include<iostream>

//void g() {
//    
//        throw "exception occured in g ";
//    
//}
//
//void f() {
//    g();
//}
//
//int main()
//{
//    try {
//        f();
//    }
//    catch (const char* e) {
//        std::cout << "exception Handled in main "<< e << std::endl;
//    }
//}
//

//void g() {
//
//    throw "exception occured in g "; //404;//"exception occured in g ";
//
//}
//
//void f() {
//    try {
//        g();
//    }
//    catch (const char* e) {
//        std::cout << "exception Handled in f() " << e << std::endl;
//    }
//}
//
//int main()
//{
//    try {
//        f();
//    }
//    catch (const char* e) {
//        std::cout << "exception Handled in main " << e << std::endl;
//    }
//    catch (...) {
//        std::cout << "default excpetion handled in main\n";
//    }
//}


void g() {
    try {
        throw "exception occured in g "; //404;//"exception occured in g ";
    }
    catch (const char* e) {
        std::cout << "exception Handled in g() itself " << e << std::endl;
        throw;
    }

}

void f() {
    try {
        g();
    }
    catch (const char* e) {
        std::cout << "exception Handled in f() " << e << std::endl;
        throw;
    }
}


//How to Detect Stack Unwinding ?
//In a destructor, stack unwinding can be detected by looking for signs of cleanup activity, such as the following :
//
//Invoking functions that release resources(e.g.close files or free memory)
//Logging messages
//Setting flags
//If any of these activities are observed in a destructor, it is likely that stack unwinding is taking place.
//
//1. Using the std::uncaught_exception():
class MyClass {
public:
    MyClass()
    {
        // allocate some resource 
    }

    ~MyClass()
    {
        if (!std::uncaught_exception()) {
            // release resource
        }

    };
};


//int main()
//{
//    try {
//        f();
//    }
//    catch (const char* e) {
//        std::cout << "exception Handled in main " << e << std::endl;
//    }
//    catch (...) {
//        std::cout << "default excpetion handled in main\n";
//    }
//}
//
