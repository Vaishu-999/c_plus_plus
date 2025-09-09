#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
int shared_data= 0;
mutex monitoringMutex;
void increment()
{

    std::unique_lock<std::mutex> mylock(monitoringMutex, std::defer_lock);
    mylock.lock();

    shared_data += 4;

    mylock.unlock();

}

int main()
{
    std::thread t1(increment);

    std::thread t2(increment);

    t1.join();
    t2.join();


    std::cout<<"shared data : " <<shared_data;
    return 0;
}