#include<iostream>
#include<memory>
using namespace std;
class Test {
public:
    Test() {
        cout << "Test obj created \n";
    }
    ~Test() {
        cout << "Test obj destroyed \n";
    }
    void print() {
        cout << "in print\n";
    }
};

void customeDeletor() {
    std::cout << "This is custome deletor for smart pointers and this does some extra functionlity in additon to destroying obj" << std::endl;
}

//int main() {
//    //Test *temp = new Test();
//    shared_ptr<Test> ptr1;
//    weak_ptr<Test> ptr2;
//    {
//        //Test *temp = new Test();
//    //unique ptr
//        unique_ptr<Test> unq_ptr = make_unique<Test>();
//        unq_ptr->print();
//        //std::unique_ptr<Test> ptr = unq_ptr;
//
//        //shared_ptr
//        shared_ptr<Test> shr_ptr = make_shared<Test>();
//        cout << "shared count " << shr_ptr.use_count() << "\n";
//        ptr1 = shr_ptr;
//        cout << "shared count " << shr_ptr.use_count() << "\n";
//        weak_ptr<Test> w_ptr = shr_ptr;
//        cout << "shared count " << shr_ptr.use_count() << "\n";
//        //shared_ptr<Test> shr_ptr1 = w_ptr;
//        cout << "shared count " << shr_ptr.use_count() << "\n";
//        //w_ptr->print();
//        ptr2 = shr_ptr;
//    }
//    cout << "shared count " << ptr1.use_count() << "\n";
//    //ptr2->print();
//    ptr1->print();
//
//    unique_ptr<int> a = make_unique<int>(10);
//    cout << *a << "\n";
//    //unique_ptr<int> b = a;
//    unique_ptr<int> b = move(a);
//    cout << *b << "\n";
//    //cout << *a << "\n";
//
//    shared_ptr<int> shr_ptr2 = make_shared<int>(25);
//    shr_ptr2 = move(b);
//    
//
//    return 0;
//}
