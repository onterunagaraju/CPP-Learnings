#include<thread>
#include <iostream>
#include<mutex>
#include<condition_variable>

std::condition_variable cv;
std::mutex mutex;
long balance = 0;

void addMoney(int money) {
    std::cout << "addMoney Called\n";
    std::unique_lock<std::mutex> ul(mutex);
    balance += money;
    std::cout << "Amount added, Current Balance is " << balance << std::endl;
    cv.notify_one();
}

void withDrawMoney(int money) {
    std::cout << "withDrawMoney Called\n";
    std::unique_lock<std::mutex> ul(mutex);
    cv.wait(ul, [] {return (balance != 0) ? true : false;});
    if (balance >= money) {
        balance -= money;
        std::cout << "Amount deducted " << money << std::endl;
    }
    else {
        std::cout << "Amount can't be deducted, Balace less than " << money << std::endl;
    }
    std::cout << "Current Balance is " << balance << std::endl;
}

int main()
{
    
    std::thread t2(withDrawMoney, 500);
    std::thread t1(addMoney, 500);
    t1.join();
    t2.join();
    return 0;
}

