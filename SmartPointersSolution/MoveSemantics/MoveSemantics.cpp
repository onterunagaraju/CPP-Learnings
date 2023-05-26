

#include <iostream>

class String {
    char* _data;
    int _size;

public:
    String(const char* data) {
        std::cout << "Created" << std::endl;
        _size = strlen(data);
        _data = new char[_size];
        memcpy(_data, data, _size);
    }

    String(const String& str) {
        std::cout << "Copied" << std::endl;
        _size = str._size;
        _data = new char[_size];
        memcpy(_data, str._data, _size);
    }

    String(String&& str) noexcept {
        std::cout << "Moved" << std::endl;
        _size = str._size;
        _data = str._data;

        str._data = nullptr;
    }

    String& operator = (String&& other) {
        std::cout << "in Move assignment operator;\n";
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;

            other._data = nullptr;
        }
        return *this;
    }

    void Print() const {
        for (size_t i = 0; i < _size; i++)
            std::cout << _data[i];
        std::cout << std::endl;
    }

    ~String() {
        std::cout << "Destroyed" << std::endl;
        delete[] _data;
    }
};

class Person {
    String _name;

public:
    Person(const String& s) : _name(s) { }
    Person(String&& s) : _name(std::move(s)) {}
    //Person(String&& s) : _name((string&&) s) {}

    void PrintName() {
        _name.Print();
    }
};

int main()
{
    Person person(String("Coder"));
    person.PrintName();

    person = String("coder1");
    person.PrintName();

    return 0;
}

