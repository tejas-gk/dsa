#include<iostream>
#include "logger.cpp"
#include<thread>
using namespace std;
// void user1(){
//     Logger *logger=Logger::getLogger();
//     logger->log("user message");
// }
// void user2(){
//     Logger *logger2=Logger::getLogger();
//     logger2->log("user message from user 2");
// }
int main(){
    // thread t1(user1);
    // thread t2(user2);

    // t1.join();
    // t2.join();
    
      Logger *logger=Logger::getLogger();
    logger->log("user message");

     Logger *logger2=Logger::getLogger();
    logger2->log("user message from user 2");
    return 0;
}