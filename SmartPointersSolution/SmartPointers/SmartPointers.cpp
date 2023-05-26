#include<iostream>
#include<memory>
#include<algorithm>
#include<vector>
using namespace std;
class Test {
public:
    Test() {
        cout << "Test obj created \n";
    }
    virtual ~Test() {
        cout << "Test obj destroyed \n";
    }
    void print() {
        cout << "in print\n";
    }

};

class Test1 : public Test {
public:
    Test1() {
        cout << "in Test1, Derived obj created \n";
    }
    ~Test1() override {
        cout << "in Test1, Derived obj destroy \n";
    }
};

int main() {
    //Test *temp = new Test();
    shared_ptr<Test> ptr1;
    weak_ptr<Test> ptr2;
    {
        //Test *temp = new Test();
    //unique ptr
        unique_ptr<Test> unq_ptr = make_unique<Test>();
        unq_ptr->print();
        unique_ptr<Test> ptr = move(unq_ptr);
        cout << " unique :";
        ptr->print();
        //shared_ptr
        shared_ptr<Test> shr_ptr = make_shared<Test>();
        cout << "shared count " << shr_ptr.use_count() << "\n";
        ptr1 = shr_ptr;
        cout << "shared count " << shr_ptr.use_count() << "\n";
        weak_ptr<Test> w_ptr = shr_ptr;
        weak_ptr<Test> w_ptr1 = shr_ptr;
        cout << "weak pointers count " << shr_ptr.use_count() << "\n";
        cout << "shared count " << shr_ptr.use_count() << "\n";
        //shared_ptr<Test> shr_ptr1 = w_ptr;
        cout << "shared count " << shr_ptr.use_count() << "\n";
        w_ptr.lock()->print();
        
        ptr2 = shr_ptr;
        
    }
    cout << "shared count " << ptr1.use_count() << "\n";
    //ptr2->print();
    ptr1->print();

    unique_ptr<int> a = make_unique<int>(10);
    cout << *a << "\n";
    //unique_ptr<int> b = a;
    unique_ptr<int> b = move(a);
    cout << *b << "\n";
    /*cout << "a " << *a << "\n";
    cout << "after a";*/
    shared_ptr<int> shr_ptr2 = make_shared<int>(25);
    shr_ptr2 = move(b);
    
    Test obj;
    //Test1 obj1;
    /*Test* obj2 = new Test1();
    delete obj2;*/
    unique_ptr<Test> obj3 = make_unique<Test1>();


  
    return 0;
}