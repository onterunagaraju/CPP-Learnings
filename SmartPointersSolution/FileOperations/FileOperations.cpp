#include <iostream>
#include<fstream>
#include<string>


class Student {
public:
    int id;
    std::string name;
    int marks;

    Student(int i,const std::string &n, int m) {
        id = i;
        name = n;
        marks = m;
    }
    std::fstream f;
    Student(const std::string& file) {
        
        f.open(file, std::ios::in);
    }

    ~Student() {
        f.close();
    }
};
int main()
{
    std::fstream myFile;
    myFile.open("Test.txt", std::ios::out);
    if (myFile.is_open()) {
        myFile << "Hello\n";
        myFile << "This is the  file\n";
        myFile << "Welcome to file\n";
        return 1;
        myFile.close();
    }

    myFile.open("Test.txt", std::ios::app);
    if (myFile.is_open()) {
        myFile << "Hello\n";
        myFile << "Welcome to c++ learning\n";
        myFile << "Thank You!!! Bye bye tata see you\n";
        myFile.close();
    }

    myFile.open("Test.txt", std::ios::in);
    if (myFile.is_open()) {

        std::string line;

        while (getline(myFile, line)) {
            std::cout << line << std::endl;
        }
        myFile.close();
    }

    Student s(2, "Nag", 975);
    

    std::fstream studentDetails;
    

    studentDetails.open("Student.txt", std::ios::out);
    if (studentDetails.is_open()) {
        studentDetails << s.id << " " << s.name << " " << s.marks << std::endl;
        studentDetails.close();
    }

    studentDetails.open("Student.txt", std::ios::in);
    if (studentDetails.is_open()) {

        studentDetails >> s.id >> s.name >> s.marks;
        std::cout << (s.id) << " " << s.name << " " << s.marks << std::endl;
        studentDetails.close();
    }
}