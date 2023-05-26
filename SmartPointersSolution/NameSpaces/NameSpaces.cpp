#include<string>
#include <iostream>

namespace {
    void display() {
        std::cout << "Unnamed namespace. its like a replacement for global variables\n";
    }
}

namespace apple {
    void print() {
        std::cout << "This is apple\n";
    }
    // nested namespace 
    namespace cherry {
        void print() {
            std::cout << "This is cherry\n";
        }
    }
}

namespace apple {
    void print1() {
        std::cout << "This is apple print1\n";
    }
}

namespace orange {
    void print() {
        std::cout << "This is orange\n";
    }
}

//void print() {
//    std::cout << "This is apple\n";
//}
//
//void print() {
//    std::cout << "This is orange\n";
//}


//inline namespaces
namespace AppVersion {
    namespace Version1 {
        void display() {
            std::cout << "display function from version 1" << std::endl;
        }
    }
    namespace Version2 {
        void display() {
            std::cout << "display function from version 2" << std::endl;
        }
    }
    inline namespace Version3 {
        void display() {
            std::cout << "display function from version 3" << std::endl;
        }
    }
}


int main()
{
    std::cout << "Enter color: \n";
    std::string color;
    std::cin >> color;
    if (color == "red") {
        apple::print();
    }
    else if (color == "orange") {
        orange::print();
    }

    apple::cherry::print();

    display();
    AppVersion::display();
}

