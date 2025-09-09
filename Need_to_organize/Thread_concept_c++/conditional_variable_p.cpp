#include<bits/stdc++.h>
using namespace std;

std::condition_variable cv;
std::mutex mtx;

bool ready = false;

void cook(){
    unique_lock<mutex> lock(mtx);
    if(cv.wait_for(lock, chrono::seconds(5), [] {return ready; })){
        cout<< "condition met, you can start the cooking by using the ingrideints " <<endl;
        }
    else{
        cout<<"today will be the fasting day, cause ingridents were not ready and day kuda ayipoyindi so no cooking no curryy" <<endl;
    }
}

int main()
{
    thread t(cook);

    this_thread::sleep_for(chrono::seconds(10));
    {
        lock_guard<mutex> lock(mtx);

        ready = true;

    }
    cv.notify_one();

    t.join();
    return 0;
}