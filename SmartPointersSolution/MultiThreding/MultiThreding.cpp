#include<thread>
#include <iostream>
#include<vector>
#include<mutex>

//class DisplayThread {
//public:
//	void operator () () {
//		for (int i = 0; i < 200; i++) {
//			std::cout << "Executing display Thread " << i << std::endl;
//		}
//	}
//};


// Race Condition
class Wallet {
	std::atomic_int Money;
	std::mutex mutex;
public:
	Wallet() {
		Money = 0;
	}
	int getMoney() { return Money; }
	void addMoney(int money) {
		//mutex.lock();
		// 
		//std::lock_guard is a class template, which implements the RAII for mutex.
		// In constructor it locks the mutex
		//std::lock_guard<std::mutex>  lockguard(mutex);
		for (int i = 0; i < money; i++) {
			Money++;
			
		}
		//mutex.unlock(); // what if we not unlocked.
		// Once function exits, then destructor
		// of lockGuard Object will be called.
		// In destructor it unlocks the mutex.
	}
};

int testMultiThreadWallet() {
	Wallet walletObj;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; i++) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObj, 1000));
	}
	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
	return walletObj.getMoney();
}


void function1() {
	for (int i = 0;i < 200;i++) {
		std::cout << "In the function1 " << i << std::endl;
	}
	std::cout << "function 1 thread id " << std::this_thread::get_id();
	std::cout << std::endl;
}

void function2() {
	for (int i = 0;i < 200;i++) {
		std::cout << "In the function2 " << i << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	int i = std::thread::hardware_concurrency();
	std::cout << "main started \n" << i ;
	/*function1();
	function2();*/
	//std::thread worker1(function1);
	//std::thread worker2(function2);
	//std::thread thread_obj = worker1 //compiler error
	// std::thread thread_obj = std::move(worker1) // thread_obj helds all responsibility of worker1
	//std::thread worker3(DisplayThread());
	//for (int i = 0;i < 200;i++) {
	//	std::cout << "From main " << i << std::endl;
	//}
	//std::cout << "worker1 thread id " << worker1.get_id() << std::endl;
	//std::cout << "worker2 thread id " << worker2.get_id() << std::endl;
	//worker1.join();
	//worker2.join();
	////worker1.join(); // it'll terminate the programe
	//if (worker1.joinable()) {
	//	worker1.join();
	//}
	

	//Race Condition
	int val = 0;
	for (int i = 0; i < 10000; i++) {
		if ((val = testMultiThreadWallet()) != 5000) {
			std::cout << "Error at count " << i << " Money in Wallet = " << val << std::endl;
		}
	}

	std::cout << "exiting from main\n";
	return 0;
}

