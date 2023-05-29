
/*

Concurrent Programing:
There are two types of Concurrent Programing basically

1. MultiProcessing :
		Each Process will have only single thread and they communicate with other process using InterProcess comunication (like 
		files pipes, message queues etc)

Advantages:
	It can run on distributed machines.

Disadvanatges:
	It takes time for a process to start as OS needs to allocate certain internal resources for a process to begin
	High Over head as OS has to take care of all processes that are running so that they dont overlap
	Slow performance when compared to multi threading.


2. Multithreading :
	In this type there is only one process but there are more than one thread and they communicate through shared memory

Advantages:
	Thread is a light weight process. Thread is faster to start where as Process is slower.
	Low over head 
	Performance is better

Disadvantages:
	Difficult to implement.
	It cant be run on distributed machines. It has to run on only a single machine as it uses shared memory
*/

/*

Definition: 
	A thread is a light weight process used to achieve parallel tasks. 
	A process can have multiple threads. 
	Every application has a default thread which is main() function. we create other threads inside this 

Examples:
	Microsoft word uses threads where one thread is used to check spellings of what we write in it and other one 
	might be used to process inputs 
	We need <thread> in order to use threads
	when we start multiple threads at the same time, we can't predict which one will start.	
*/



#include "pch.h"
#include <iostream>
#include <thread> 
#include <chrono>
#include <string>
#include <mutex>
using namespace std;
using namespace std::chrono;

/********************************************* Use of threads *****************************************/
/*
	From the follwing program it is evident that the time taken to perform those two functions 
	it takes more time without threads but takes half time using threads 
*/



//unsigned long long OddSum;
//unsigned long long EvenSum;
//
//void  FindoddSum(unsigned long long  nStart, unsigned long long  nEnd)
//{
//	unsigned long long  sum = 0;
//	for (unsigned long long  i = nStart; i < nEnd; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum = sum + i;
//		}
//	}
//
//	OddSum =  sum;
//}
//
//void FindEvenSum(unsigned long long  nStart, unsigned long long  nEnd)
//{
//	unsigned long long  sum = 0;
//	for (unsigned long long  i = nStart; i < nEnd; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum = sum + i;
//		}
//	}
//	EvenSum =  sum;
//}
//
//
//
//int main()//thread
//{
//	unsigned long long  nStart = 0, nEnd = 19000000;
//
//	auto Starttime = high_resolution_clock::now(); //time before executing functions
//
//	//using threads
//	std::thread t1(FindoddSum, nStart, nEnd); //assignin a function to a thread
//	std::thread t2(FindEvenSum, nStart, nEnd); 
//
//	t1.join(); //joining the thread to main thread 
//	t2.join();
//
//
//	////without threads
//	//FindoddSum(nStart, nEnd); //1st
//	//FindEvenSum(nStart, nEnd); //2nd
//
//	auto Endtime = high_resolution_clock::now(); ////time after executing functions
//
//	auto duration = duration_cast<microseconds>(Endtime - Starttime); //difference time 
//		
//	//cout << OddSum << endl;
//	//cout << EvenSum << endl;
//
//	cout << (duration.count()/ 1000)  <<  "   milliseconds" <<endl; //5 seconds
//
//	return 0;
//}



/***************************************  1.  Ways to Create Threads *****************************************/

 //1. Using Function Pointer 
//void func(int x)
//{
//	while (x-- > 0)
//	{
//		cout << x << endl;
//	}
//}
//
//void main()
//{
//	std::thread t1(func, 10); //func is a function pointer here 
//	//t1.join(); //it means main thread waits for t1 to finish its job.if we dont join a thread to main thread then, 
//					 //main thread will finish its tasks and ends there and doesnt bother about other threads so
//					//the thread will exists even after main exits and this can lead to undefined behaviour 
//
//	cout << "test" << endl;
//	t1.join();
//}

//2. Using Lambda expression
//void main()
//{
//	auto func = [](int x) 
//	{
//		while (x-- > 0) 
//			cout << x << endl; 
//	}; //lambda function
//
//	std::thread tLamda(func, 20);
//	tLamda.join();
//
//
//	/***** OR *******/
//
//
//	std::thread tLamda([](int x))  //lambda function can be directly passed to thread 
//	{
//		while (x-- > 0)
//			cout << x << endl;
//	}, 20);
//	tLamda.join();
//}


////3. Using Functor (Function Object)
////A functor is pretty much just a class which defines the operator(). 
//That lets you create objects which "look like" a function:
//
//class Base
//{
//public:
//	void operator()(int x)  //
//	{
//		while (x-- > 0)
//		{
//			cout << x << endl;
//		}
//	}
//
//};
//
//
//void main()
//{
//
////1st way 
//	Base obj;
//	std::thread t1(obj, 20);
//
////2nd way 
//	std::thread t1(Base(), 20);    
//	t1.join();
//
////3. we can use Bind as well
//	std::bind(Base(), 15);
//}


//// 4. Using Non Static Member Functions
//class Base
//{
//public:
//	void run(int x)  //
//	{
//		while (x-- > 0)
//		{
//			cout << x << endl;
//		}
//	}
//};
//
//void main()
//{
//	Base obj;
//	std::thread t1(&Base::run, std::ref(obj), 20); //syntax to invoke a function using thread
//	t1.join();
//}.


//5. Using static member functions : In this case we dont need an object to be passed as we are invoking a static function
//class Base
//{
//public:
//	static void run(int x)  //
//	{
//		while (x-- > 0)
//		{
//			cout << x << endl;
//		}
//	}
//};
//
//void main()
//{
//	std::thread t1(&Base::run, 20); 
//	t1.join();
//}


////6. Syntax to  pass a variable as a refernce to a function called using thread 
//void func(int& x)  //argument should be passed as &
//{
//	x = 5;
//}
//void main()
//{
//	int i = 10;
//	std::thread t1(func, std::ref(i)); //we need to use std:ref to tell the compiler that i is passed as reference to func 
//	t1.join();
//
//	cout << i << endl;
//}


//7. We can also move our argument permanently to thread function. Once we do that it will be no longer available in main 
// output of the follwing program is only thread and it doesnt print the s variable in main as its owenership is completely moved to thread
//void func(string x) 
//{
//	x = "thread";
//	cout << x << endl;
//}
//void main()
//{
//	string s = "test";
//	std::thread t1(func, std::move(s));
//	t1.join();
//
//	cout << s << endl; //doesnt print anything 
//}



//8. A thread can't be copied or assigned to another thread. 
//The assignment operator and copy constructor is deleted so that it cant be invoked
 //we can only move thread to another
//void func() 
//{
//}
//void main()
//{
//	std::thread t1(func); 
//	t1.join();
//	//std::thread t2 = t1; //compile error
//	//std::thread t2 = std::move(t1); //works fine. t1 will be empty after moving and t2 helds all responsibility of t1 
//}


////9.we can get the id associated with thread using get_id() function. This can come handy when we need to identify a particular 
////thread when we have lot of threads
void func() 
{

	//cout << std::this_thread::get_id()   << endl;
}
//void main()
//{
//	cout << std::this_thread::get_id() << endl; // this prints the id of the main thread
//
//	std::thread t1(func); 
//	cout << "t1 id is" << t1.get_id() << endl;// this prints the id of the t1 thread
//	t1.join();
//
//	std::thread t2(func);
//	cout << "t2 id is"   << t2.get_id() << endl;// this prints the id of the t1 thread
//	t2.join();
//
//	cout << std::thread::hardware_concurrency() << endl; //This can give us maximum number of threads that we can create. Its only a guide 
//}












/* ************************************* 2. Join and Detach ************************************************************************** /  // NOLINT(clang-diagnostic-comment)
/*

When we create a thread "WE SHOULD EITHER CALL JOIN OR DETACH ON IT BEFORE THAT THREAD GOES OUT OF SCOPE"

Join:
	1. As soon as we create a thread, its invoked and it starts acting on the function its invoked for
	We should call join to attach it to the main thread and if we dont call join, then the thread still persists even after main dies 
	and it might lead to a crash. 
	Join also tells the compiler that it should wait untill it finishes the job of thread in that function.
	2. Double join will cause program termination/crash because it make no sense in calling join twice (as the task is already done in the first call)	
	3. In order to avoid calling join twice , we can use a function named Joinable() to check if thread can be joined or not.
	Its always better we check Joinable before calling Join()

Detach:
	1. The detach function is used to detach the newly created thread from its parent thread 
	2. Its better we check joinable() before we detach. Double detach will also cause termination of program.
	Very Imp: If we are detaching a thread after creating it and if main function finishes its job earlier than the thread's job then 
	the thread's job is suspended, it means thread will not do anything on the function its invoked for

the output in the follwing program is: 
main
main ended
*/
//void run()
//{
//	cout << "  run" << endl; //this line will not be printed as its detached and main thread finishes its task of printing the two messages before 
//										//thread could print run
//}
//
//int main()
//{
//	std::thread t1(run); 
//	cout<<"main"<<endl;
//	t1.detach();
//	cout<<"main ended"<<endl;
//	cout << t1.get_id() << endl;
//
//	return 0;
//}

//Why does it crash when we dont call either join or detach on a thread ?? 
//
//Note: So we should call either join or detach on a thread because if 
//we dont then the thread object calls its destructor and there it checks 
//if its joinable() which will be true because we have not joined it and it terminates the program if its joinable 


//
//void run()
//{
//	cout << "run" << endl;
//}
//
//int main()
//{
//	std::thread t1(run); //thread begins here an starts acting on run function
//	
//	if (t1.joinable()) //condition to be checked for joining a thread
//	{
//		t1.join(); //program crashes if we dont call thread
//		cout << "1st time " << endl;
//		t1.detach();
//	}
//
//
//	//t1.join(); //program crashes here as we called join twice 
//
//	return 0;
//}


/** what if there is return statement in between thread creation and joining or detaching ?  like in the follwing code  *////
//
//void run()
//{
//}
//
//void main()
//{
//	std::thread t1(run);
//
///*
//	Here if we have a return statement or code that crashes then t1 will not join and program can crash.
//		1. we can use try catch to make sure that join is called. 
//		2. we can use RAII (Resource acqusition is initilization) by wrapping the thread object in a class something like wrapperclass(t1) such that 
//	      whenever thread goes out of scope the destructor of wrapperclass gets called and thread can be safely joined/detached 
//			(something similar to smart pointers class)
//*/
//	
//	t1.join();
//}




/*******************************************  3. Mutex and Race Condition ******************************************************/
/*
The output of the follwing program is too clumpsy because both main and t1 tries to fight for common resource "cout" in this case
Race Condition:
	It is a situation where two or more threads fights for same resource at the same time. (Just like a real world race)

solution:
	We need to synchronize the common resource available. synchronization means, somehow handling the resource so that its 
	availabe to only one resource at any point of time 

Types of synchronization objects 
	1. mutex - we need #include <mutex>
	2. semaphore
	3. events

	The program prints fine after we utilize the function shared_print for prinitng 
*/


//#include <mutex>
//
//std::mutex mymutex;
//void shared_print(string strmsg, int id)
//{
//	//The follwing is the process of synchronization. The thread that arrrives first to this place locks the common resource and unlocks after 
//	// it uses it. So threads wont fight as other thread waits until the first thread finishes using common resource.
//	//mymutex.lock();//locking common resource
//	cout << strmsg << id << endl;
//	//mymutex.unlock(); //unlock common resource
//
//	/*problem: 
//		what if mutex locks properly but something goes wrong before it unlocks ?? other threads can never use the resource as 
//		first approached thread will lock it forever
//	solution:
//		we can use RAII i.e. wrap the mutext in a class so that when mutext goes out of scope it is automatically deleted/unlocked */
//		
//	//std::lock_guard<mutex> lguard(mymutex);//so using lockguard of mutex type. even though the next statement of this line returns the lock guards
//	//cout << strmsg << id << endl;				// takes care of releasing the mutex
//}
//
//
//int m_nvalue = 0;
//
//void func()
//{
//	for (int i = 0; i > -10000; i--)
//	{
//		mymutex.lock();
//		cout << "func " << m_nvalue++ << endl;
//		mymutex.unlock();
//		//cout << "from t1" << i << endl;
//		//shared_print("from t1 ", i);
//	}
//}
//
//void main()
//{
//	std::thread t1(func);
//
//	std::thread t2(func);
//	
//	/*for (int i = 0; i < 10000; i++)
//	{
//		mymutex.lock();
//		cout << "main  " << m_nvalue++ << endl;
//		mymutex.unlock();
//	}*/
//		
//		//cout << "from main"<< i << endl;
//		//shared_print("from main ", i);
//	t1.join();
//
//	t2.join();
//}




/***********************************  4. Dead lock situation *********************************************/
/*
	Dead lock is a situation where there are more than one mutex (it can be any other synchornization objects) and more than one thread and 
	there comes a situation where each thread locks one of the mutexes and wait for other.

problem:
	In the follwing program there are two threads t1 and t2 and two mutexes m1 and m2 are used
	t1 locks m2 in oddcount
	t2 locks m1 in even count 
	t1 will wait for t2 to release m1 and t2 will wait for t1 to release m2 and it goes to a deadlock situation

solution:
	1. we can use adopt_lock mechanism as in the follwing code
	2. Use mutexes in the same order everywhere in the program 
	3. Try to use only one mutex as far as possible
*/

//

//
//int i = 0;
//std::mutex m1;
//std::mutex m2;
//
//void oddcount()
//{
//	m2.lock();
//	m1.lock();
//	i++;
//	m2.unlock();
//	m1.unlock();
//
//	////1. we can avoid deadlock using the follwing code
//	//std::lock(m1, m2);
//	//std::lock_guard<mutex> lg2(m2, std::adopt_lock); //This statement tells the guard lg2 that m2 is already locked in the above statment and just adopt to it
//	//std::lock_guard<mutex> lg1(m1, std::adopt_lock);
//	//i++;
//
//
//	////2. Lock mutexes in the same order m1 first and m2 next. The same order in the other funtion also(evencount function)
//	//m1.lock();
//	//m2.lock();
//	//i++;
//	//m1.unlock();
//	//m2.unlock();
//	//i++;	
//}
//
//
//void evencount()
//{
//	m1.lock();
//	m2.lock();
//	i++;
//	m1.unlock();
//	m2.unlock();
//
//	//we can avoid deadlock using the follwing code
//	std::lock(m1, m2);
//	std::lock_guard<mutex> lg1(m1, std::adopt_lock);
//	std::lock_guard<mutex> lg2(m2, std::adopt_lock);
//}
//
//
//void main()
//{
//	std::thread t1(oddcount);
//	std::thread t2(evencount);
//
//
//	t1.join();
//	t2.join();
//}




/*******************************************  5. Unique lock and lazy Initialization *********************/
/*
unique_lock is something similar to lock_guard but has got more flexibility than lock_guard
	1. Using unique_lock we can actually lock only certain portion of code and unlock after wards
	2. We can lock the mutex sometime later when we need, we need not lock right at the moment of attaching the mutex to unique lock
	3. We can lock and unlock mutiple times unlike lock_guard
	4. We cant copy a unique_lock but moved it but lock_guard cant even be moved 

Note:
	Use lock_guard when you want simple features of lock as it has little overhead when compared to unique_lock
*/


//std::mutex mymutex;
//
//void func()
//{
//	//std::lock_guard<mutex> lg(mymutex); //using the lock guard we can only lock the mutex and its not in our control to unlock it
//	////so for all the statements below this line, the lock is applied untill the lg goes out of scope
//
//	//1. We can unlock by using the unique_lock like 
//	std::unique_lock<mutex> ulock(mymutex);
//	for (int i = 0; i > -100; i--)
//		cout << "from t1" << i << endl;
//	ulock.unlock(); //we can unlock here so that only code in the for loop is locked 
//
//	//2. unique_lock also gives fleibility of when to lock mutex. ITS NOT NECESSARY TO LOCK MUTEX WHEN YOU CREATE IT using std::deferred_lock
//	std::unique_lock<mutex> ulock(mymutex, std::defer_lock); //Here i am not locking my mutex yet. I have only attached the mutex to my unique_lock
//	ulock.lock(); //Here i am actually locking the mutex
//	for (int i = 0; i > -100; i--)
//		cout << "from t1" << i << endl;
//	ulock.unlock(); //we can unlock here so that only code in the for loop is locked 
//
//
//	//3. We can lock and unlock mutiple times 
//	std::unique_lock<mutex> ulock(mymutex);
//	for (int i = 0; i > -100; i--)
//		cout << "from t1" << i << endl;
//	ulock.unlock(); //we can unlock here so that only code in the for loop is locked 
//	mymutex.lock();
//	mymutex.unlock();
//}
//
//void main()
//{
//	std::thread t1(func);
//	for (int i = 0; i < 100; i++)
//		cout << "from main"<< i << endl;
//
//	t1.join();
//}
//
//

/*******************************  6. call_once  ********************/
/*

This is a kind of lock mechanism where we can lock a statement that should be executed only once like opening a file
We can ofcourse use lock and unlock or a lock_guard or a unique_lock for the same purpose
*/

//std::once_flag Oflag;
//void func()
//{
//	//do something like opening a file
//}
//
//void main()
//{
//	std::call_once(Oflag, func); //This calls  the func only once 
//}






/*****************************   7. condition variables     *******************************/
/*

Condition variables comes for help when we cant handle a situation of using mutex alone
If certain thread is waiting for another thread's action, we can use condition variables to notify the waiting thread/threads that 
the task is over

*/

//std::mutex m1;
//std::condition_variable cv;
//
//long balance = 0;
//
//void addmoney(long money)
//{
//	std::lock_guard<std::mutex> guard(m1);
//	balance += money;
//	cv.notify_one(); //This notifies the thread tdrawmoney that it has finished its job 
//							//we can also use cv_notify_all() if more than one thread is waiting for it
//}
//
//void DrawMoney(long money)
//{
//	std::unique_lock<std::mutex> ulock(m1); //the thread tdrawmoney tries to lock the mutex but release as soon as it has a condition failing in the next line
//	 //Conditon variable is used to check balance and allows the next statement to be executed only when its greater than money 
//	cv.wait(ulock, [](long money) { return balance > money ? true : false; });
//	balance = balance - money;																
//	
//}
//
//void main()
//{
//	std::thread taddmoney(addmoney, 500);
//	std::thread tdrawmoney(DrawMoney, 500);
//
//	taddmoney.join();
//	tdrawmoney.join();
//}


/******************************************    8. Future, Promise and async     ****************************************/
/*
Problem 1:
	So far we have only called functions using threads and did some functionality inside them but what if  we want to return 
	some value from the function we are calling using threads 

*/

////solution 1
//// we can pass a reference value to get the result but since x is a shared resource we need to safe guard it using a mutex and we 
//// also probably need a condition variable to tell the main function that a value is set and you can read
//// For a simple return value, we need to do a lot of stuff and hence we can use help of async
//void factorial(int N , int &x)
//{
//	int res;
//	for (int i = N; i > 1; i--)
//		res = res * i; //Now we want the factorial value to be returned to main
//	x = res;
//}
//
//void main()
//{
//	int value;
//	std::thread t1(factorial, 3, std::ref(value));
//	t1.join();
//
//}


#include <future>
//solution 2 : using std::async
//async function may or may not create a new thread to do its task. we can manage it by using the key words
	//	1. std::launch::async - create a new thread to do the task 
	// 2. std::launch::deferred -  this does not create a new thread when async is called but the called function gets executed using the SAME THREAD when get() is called
	// 3. IF we use std::launch::async | std::launch::deferred	- compiler will decide to create a new thread or not. This is the default argument of the async function

//int factorial(int N )
//{
//	int res;
//	for (int i = N; i > 1; i--)
//		res = res * i; //Now we want the factorial value to be returned to main
//}
//
//void main()
//{
//	/*std::thread t1(factorial, 3);
//	t1.join();*/
//
//	//thread is a class so it cant return anything where as async is a function and it returns a future object
//	// so we can use something like
//	std::future<int> res = std::async(factorial, 3); //as factorial function returns int value we need to have a future object of int type <int>
//	res.get(); //we can fetch the value from res using a get method. This also waits until the child thread return a value 
//	// WE CAN CALL get() from future ONLY ONCE and program crash if we call more than once
//}




// Now if want to pass a value to child thread NOT WHEN WE CREATE THREAD BUT SOMETIME IN FUTURE  like I dont want to pass the the number 
// to my factorial function immediately but i wanted to take it from user an pass it later on  then how should we do it

// we can do that using the promise and future combination
// If we promise something to child and doesnt send anything then the program throws exception when child thread calls get()
// We cant copy either promise or future but we can move them 

//int factorial(std::future<int>& fut)
//{
//	int res = 1;
//	int N = fut.get(); //Here we are getting the value from a future object for which we need to calculate the factorial
//
//	for (int i = N; i > 1; i--)
//		res = res * i; //Now we want the factorial value to be returned to main
//
//	return res;
//}
//
//void main()
//{
//	std::promise<int> prom;
//	std::future<int> fut = prom.get_future();
//	std::future<int> res = std::async(std::launch::async, factorial, std::ref(fut));
//	
//	// I can take value from user and then send it to child thread
//	prom.set_value(3); //sending value to child thread
//	int factorial = res.get(); //getting the result
//
//	int j = 10;
//}


/*
Lets say we want to call our factorial function 10 times. We cant use same future object because we only call get() only once in child
we need to create 10 future objects and call 10 times which is not a feasible solution.
C++ provides us with something called shared_future which can be copied and then passed to function any number of times

From above example 
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();
	std::shared_future<int> sf = fut.share(); //we can create a shared_future like this and now we can call with sf as value
	std::async(std::launch::async, factorial, sf);
	std::async(std::launch::async, factorial, sf);
	std::async(std::launch::async, factorial, sf);
*/


/*****************************************************    9. Timings  **************************************************************/

//void func(int i)
//{
//
//}

//void main()
//{
//	std::thread t1(func, 6);
//	std::this_thread::sleep_for(std::chrono::milliseconds(3)); //asking main thread to sleep for 3 milli seconds
//	std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();
//	std::this_thread::sleep_until(tp); //sleep for so much time
//
//
//	std::mutex m;
//	std::lock_guard<mutex> lg(m);
//	std::unique_lock<mutex> ul(m);
//	ul.try_lock(); //tries to lock mutex and returns if its not able to
//	ul.try_lock_for(std::chrono::microseconds(500)); //try to lock mutex. If not able to do so in 500 microseconds just return
//	ul.try_lock_until(tp); //try locking for given time 
//
//
//	std::condition_variable cv;
//	cv.wait_for(ul, std::chrono::microseconds(4)); 
//	cv.wait_until(ul, tp);
//
//	std::promise<int>pr;
//	std::future<int> fu = pr.get_future();
//
//	fu.get(); //waits  untill child thread function finishes its tasks
//	fu.wait(); //waits for data to be available ..Actually get() internally calls wait()
//	fu.wait_for(std::chrono::microseconds(4));//wait for 4 micro seconds
//}





/***************************************** 10. packaged_task *******************************************/

#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>


boost::asio::thread_pool threadPool(4);
std::vector<std::future<std::string>> strfullname;


std::string GetFullname(std::string strFirstName, std::string strSecondName)
{
	std::string strFullName = strFirstName + strSecondName;
	return strFullName;
}

void createthreadpool(std::string strFirstName, std::string strSecondName)
{
	std::packaged_task<std::string()> pt(std::bind(GetFullname, strFirstName, strSecondName));
	strfullname.push_back(pt.get_future());

	boost::asio::post(threadPool, std::move(pt));

	int i = 10;
}


void main()
{
	for(int i = 0; i < 20; i++)
	createthreadpool("sandeep", "kota");

	for (auto& fname : strfullname)
		cout << fname.get() << endl;
}


