#include<iostream>
#include<exception>

using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() {
        return "Entered age is invalid, please enter age greater than 18 ";
    }
};

//int main() {
//    cout << "Hello World!" << endl;
//    int age;
//    cin >> age;
//    try {
//        if (age < 18) {
//            InvalidAgeException exption;
//            throw exption;
//        }
//
//    }
//    catch (InvalidAgeException& exption) {
//        cout << "Custome exception captured\n";
//        cout << exption.what();
//    }
//
//}