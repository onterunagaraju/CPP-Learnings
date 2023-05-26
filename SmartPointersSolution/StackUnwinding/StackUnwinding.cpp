
#include <iostream>

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

int main()
{
    try {
        f();
    }
    catch (const char* e) {
        std::cout << "exception Handled in main " << e << std::endl;
    }
    catch (...) {
        std::cout << "default excpetion handled in main\n";
    }
}

