#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <functional>

using namespace std;
// Function to print vector
void printVector(vector<int> v)
{
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
        {
            std::cout << i << " ";
        });
    cout << endl;
}


//int main()
//{
//    vector<int> v{ 4, 1, 3, 5, 2, 3, 1, 7 };
//    printVector(v);
//    sort(v.begin(), v.end(), [](const int& a, const int& b) {
//        return b < a;
//        });
//    cout << "sorted in decending order: \n";
//    printVector(v);
//    // below snippet find first number greater than 4
//    // find_if searches for an element for which
//    // function(third argument) returns true
//    vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
//        {
//            return i > 4;
//        });
//
//    cout << "First number greater than 4 is : " << *p << endl;
//
//
//    // function to sort vector, lambda expression is for sorting in
//    // non-increasing order Compiler can make out return type as
//    // bool, but shown here just for explanation
//    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
//        {
//            return a > b;
//        });
//
//    printVector(v);
//
//    // function to count numbers greater than or equal to 5
//    int count_5 = count_if(v.begin(), v.end(), [](int a) {
//        return (a >= 5);});
//    cout << "The number of elements greater than or equal to 5 is : "
//        << count_5 << endl;
//
//    //     We can also access function by storing this into variable
//    auto square = [](int i)
//    {
//        return i * i;
//    };
//
//    cout << "Square of 5 is : " << square(5) << endl;
//
//    // accumulate function accumulate the container on the basis of
//    // function provided as third argument
//    int arr[] = { 1,2,3,4,5 };
//    int ans = accumulate(arr, arr + 5, 1, [](int i, int j) {
//        return i * j;
//        });
//    cout << " Accumulated value : " << ans << endl;
//
//    vector<int> v1 = { 3, 1, 7, 9 };
//    vector<int> v2 = { 10, 2, 7, 16, 9 };
//
//    //  access v1 and v2 by reference
//    auto pushinto = [&](int m)
//    {
//        v1.push_back(m);
//        v2.push_back(m);
//    };
//
//    // it pushes 20 in both v1 and v2
//    pushinto(20);
//
//    // access v1 by copy
//    auto traverse = [v1]()
//    {
//        for (auto p = v1.begin(); p != v1.end(); p++)
//        {
//            cout << *p << " ";
//        }
//    };
//
//    traverse();
//    cout << endl;
//    int N = 5;
//    int count_N = count_if(v1.begin(), v1.end(), [=](int a)
//        {
//            return (a >= N);
//        });
//
//    cout << "The number of elements greater than or equal to 5 is : "
//        << count_N << endl;
//
//    //factorial
//
//    auto fac = [](int n) {
//        if (n == 0 || n == 1)
//            return 1;
//
//        else {
//            int fact = 1;
//            for (int i = 1; i <= n;i++) {
//                fact *= i;
//            }
//            return fact;
//        }
//    };
//
//    cout << "factrorial of 6: " << fac(6) << endl;
//    
//    // Recursion using lambdas
//    N = 12345;
//    //if you declare like below it will give error.
//    /*auto PrintReverse = [&N]() {
//        if (N == 0) return;
//        cout << N%10 << endl;
//        N = N / 10;
//        PrintReverse();
//    }*/
//
//    /*There are two ways to resolve the error above :
//
//    1. By passing the function itself, to the function argument :*/
//    // Function itself as a parameter
//    auto printReverse = [&](auto&& printReverse) {
//        if (N == 0)
//            return;
//        cout << N % 10 << " ";
//        N = N / 10;
//        printReverse(printReverse);
//    };
//
//    // Function as an argument
//    printReverse(printReverse);
//
//    // 2. By declaring the function and definition:
//    // Function < return type(parameter
//        // types) > functionName
//
//        // Don't forget to include functional
//        // header
//
//        // Declaration
//        //function<void()> Reverse;
//
//        //Reverse = [&]() {
//        //    if (N == 0)
//        //        return;
//
//        //    // Definition
//        //    cout << N % 10 << " ";
//        //    N /= 10;
//        //    Reverse();
//        //};
//        //Reverse();
//
//    // Declaration and definition
//    //cout << "before reverse " << endl;
//    N = 12345;
//    function<void()> Reverse = [&]() {
//        if (N == 0) return 0;
//        cout << N % 10 << " ";
//        N = N / 10;
//        Reverse();
//    };
//    Reverse();
//    //cout << "After Reverse" << endl;
//    auto fun = [](int x, int y) -> double {
//        return (x + y) / 2;
//    };
//    cout << fun(7, 8);
//
//    // Generalized lambda
//    // before c++14 for different types of data we need to create different lambdas according to type
//    auto add = [](int a, int b) {
//        return a + b;
//    };
//    auto add1 = [](float a, float b) {
//        return a + b;
//    };
//
//    // we can use templates for that
//    /*template<typename T>
//    [](T a, T b) -> T { return a + b };*/
//
//    // after c++14 auto keyword came into existance and we can use that for genric programming
//    auto addNumbers = [](auto a, auto b) {
//        return a + b;
//    };
//    cout << "Int addition " << addNumbers(1, 2) << endl;
//    cout << "Float addition " << addNumbers(1.1, 2.5) << endl;
//
//    return 0;
//}
