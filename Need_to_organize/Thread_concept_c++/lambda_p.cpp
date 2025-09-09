#include <iostream>
#include <thread> 
using namespace std;
int main()
{
    int m = 10 ;
    static int n = 9;
    std::thread t([](int m){
        cout<<"m value : "<< m <<endl;
        cout<<"static n value : "<< n <<endl;
    }, m);


    t.join();
    return 0;

}
