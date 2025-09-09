#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void sayHello()
{
    cout<<"Hello from thread using bits \n"; 

    for(int i =0; i<10000000 ; i++)
    {
        cnt++;
    }
}
int main()
{
    thread t(sayHello);
    thread t2(sayHello);
    t.join();
    t2.join();
    cout<<"Hello from main";
    cout<<cnt;
    return 0;
}