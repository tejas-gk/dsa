#include<iostream>
#include "logger.hpp"
using namespace std;
int Logger::counter=0;
Logger *Logger::loggerInstance=NULL;//nullptr
Logger::Logger(){
    counter++;
    cout<<"Logger created"<<endl;
}
void Logger::log(string msg)
{
    cout<<msg<<endl;
}
Logger *Logger::getLogger()
{
    if(loggerInstance==NULL)
    {
        loggerInstance=new Logger();
    }
    return loggerInstance;
}
