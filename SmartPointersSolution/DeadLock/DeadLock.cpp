#include<thread>
#include <iostream>
#include<mutex>
#include<future>

std::mutex m1, m2;
//deadlocks can avoided by maintaining consistency in the ordering of the locking and unlocking of mutexes:
void threadA() {
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    m2.lock();
    std::cout << "Thread A \n";
    m1.unlock();
    m2.unlock();
}

void threadB() {
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    m1.lock();
    std::cout << "Thread B \n";
    m2.unlock();
    m1.unlock();

   /* m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    m2.lock();
    std::cout << "Thread B \n";
    m2.unlock();
    m1.unlock();*/
}


//void factorial(int n, int& x) {
//    int fact = 1;
//    for (int i = 1; i <= n; i++) {
//        fact *= i;
//    }
//    x = fact;
//}

//int factorial(int n) {
//    int fact = 1;
//    for (int i = 1; i <= n; i++) {
//        fact *= i;
//    }
//    return fact;
//}



int factorial(std::future<int>& fut)
{
	int res = 1;
	int N = fut.get(); //Here we are getting the value from a future object for which we need to calculate the factorial

	for (int i = N; i > 1; i--)
		res = res * i; 

	return res;
}



int main()
{
    std::thread t1(threadA);
    std::thread t2(threadB);
    int val;
    //std::thread t3(factorial, 5, std::move(val));

    /*std::future<int> fut = std::async(factorial, 5);
    int res = fut.get();*/

    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::future<int> res = std::async(std::launch::async, factorial, std::ref(fut));
    	
    // I can take value from user and then send it to child thread
    prom.set_value(3); //sending value to child thread
    int factorial = res.get(); //getting the result

    t1.join();
    t2.join();
    //t3.join();
    return 0;
}

