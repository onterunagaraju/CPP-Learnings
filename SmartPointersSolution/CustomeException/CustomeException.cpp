#include <iostream>
#include <exception>
using namespace std;

class CustomeException : public exception {
public:
    const char* what() {
        return "Custome Exception Occured ";
    }
};

int main() {
    cout << "Hello World!" << endl;
    int age;
    cin >> age;
    try {
        if (age < 18) {
            CustomeException exption;
            throw exption;
        }

    }
    catch (CustomeException& exption) {
        cout << "Custome exception captured\n";
        cout << exption.what();
    }

}