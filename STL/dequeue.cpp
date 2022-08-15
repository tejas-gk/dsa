#include<iostream>
#include<deque>

// deque is a double ended queue
// deque used to store data in contiguous memory
// deque if used as variable
int deque_variable(){
    std::deque<int> d;
    d.push_back(8);
    d.push_back(0);
    d.push_back(0);
    d.push_back(8);
    d.push_front(0);
    d.pop_front();
    for(std::deque<int>::iterator itr=d.begin();itr!=d.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<d.size()<<std::endl;
    d.pop_back();
    for(std::deque<int>::iterator itr=d.begin();itr!=d.end();++itr)  {
        std::cout<<*itr;
    }
}
// deque if used as function parameter
int deque_function_parameter(std::deque<int> d){
    for(std::deque<int>::iterator itr=d.begin();itr!=d.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<d.size()<<std::endl;
    d.pop_front();
}
// deque if used as function return value
std::deque<int> deque_function_return_value(){
    std::deque<int> d;
    d.push_back(8);
    d.push_back(0);
    d.push_back(0);
    d.push_back(8);
    return d;
}
// deque if used as pointer parameter
int deque_pointer_parameter(std::deque<int> *d){
    for(std::deque<int>::iterator itr=d->begin();itr!=d->end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<d->size()<<std::endl;
    d->pop_front();
}
