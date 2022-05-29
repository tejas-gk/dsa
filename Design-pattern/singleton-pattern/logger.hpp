#ifndef logger_h
#define logger_h

#include<string>
#include<iostream>
using namespace std;

class Logger {
    private:
    static int counter;
    static Logger *loggerInstance;
     Logger();
    public:
    static Logger *getLogger();//return instance
    void log(string msg);
};



#endif
