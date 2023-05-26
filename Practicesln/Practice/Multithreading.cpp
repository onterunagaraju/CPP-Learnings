#include<iostream>
#include<thread>

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

//int main()
//{
//	std::cout << "main started \n";
//	auto startTime = std::chrono::high_resolution_clock::now();
//	//// without using threads
//	//function1();
//	//function2();
//
//	// with using threads
//	std::thread worker1(function1);
//	std::thread worker2(function2);
//	worker1.join();
//	worker2.join();
//	auto endTime = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
//
//	std::cout << "duration: " << duration.count() / 1000 << "Milliseconds";
//	return 0;
//}