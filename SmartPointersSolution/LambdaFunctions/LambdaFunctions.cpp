

#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
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


int main()
{
    vector<int> v{ 4, 1, 3, 5, 2, 3, 1, 7 };
    printVector(v);
    sort(v.begin(), v.end(), [](const int& a,const int& b) {
        return b < a;
        });
    cout << "sorted in decending order: \n";
    printVector(v);
    // below snippet find first number greater than 4
    // find_if searches for an element for which
    // function(third argument) returns true
    vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
        {
            return i > 4;
        });

    cout << "First number greater than 4 is : " << *p << endl;


    // function to sort vector, lambda expression is for sorting in
    // non-increasing order Compiler can make out return type as
    // bool, but shown here just for explanation
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
        {
            return a > b;
        });

    printVector(v);

    // function to count numbers greater than or equal to 5
    int count_5 = count_if(v.begin(), v.end(), [](int a) {
        return (a >= 5);});
    cout << "The number of elements greater than or equal to 5 is : "
        << count_5 << endl;

    //     We can also access function by storing this into variable
    auto square = [](int i)
    {
        return i * i;
    };

    cout << "Square of 5 is : " << square(5) << endl;

    // accumulate function accumulate the container on the basis of
    // function provided as third argument
    int arr[] = { 1,2,3,4,5 };
    int ans = accumulate(arr, arr + 5, 1, [](int i, int j) {
        return i * j;
        });
    cout << " Accumulated value : " << ans << endl;

    vector<int> v1 = { 3, 1, 7, 9 };
    vector<int> v2 = { 10, 2, 7, 16, 9 };

    //  access v1 and v2 by reference
    auto pushinto = [&](int m)
    {
        v1.push_back(m);
        v2.push_back(m);
    };

    // it pushes 20 in both v1 and v2
    pushinto(20);

    // access v1 by copy
    auto traverse = [v1]()
    {
        for (auto p = v1.begin(); p != v1.end(); p++)
        {
            cout << *p << " ";
        }
    };
    
    traverse();
    cout << endl;
    int N = 5;
    int count_N = count_if(v1.begin(), v1.end(), [=](int a)
        {
            return (a >= N);
        });

    cout << "The number of elements greater than or equal to 5 is : "
        << count_N << endl;

    //factorial
    
    auto fac = [](int n) {
        if (n == 0 || n == 1)
            return 1;
        
        else {
            int fact = 1;
            for (int i = 1; i <= n;i++) {
                fact *= i;
            }
            return fact;
        }
    };

    cout << "factrorial of 6: " << fac(6) << endl;

    auto fun = [](int x,int y) -> double {
        return (x + y) / 2;
    };
    cout << fun(7, 8);

	return 0;
}

