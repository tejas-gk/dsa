#include<thread>
#include<iostream>
#include<mutex>
#include<string>
using namespace std;
int main(){
    
    thread t1([](){
        std::cout<<"hello"<<std::endl;
    });
   thread t2([](){
        std::cout<<"hello"<<std::endl;
    });

    t1.join();
    t2.join();
    return 0;
}