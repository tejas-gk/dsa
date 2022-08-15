#include<iostream>
#include<list>

// list is a doubly linked list
// list if used as variable
int list_variable(){
    std::list<int> l;
    for(int i=0;i<10;i++)
    {
        l.push_back(i);
        l.push_front(i-1);
    }
    l.sort();
    l.pop_back();
    l.reverse();
    l.pop_front();
    std::cout<<l.front()<<std::endl;
    std::cout<<l.back()<<std::endl;
}
// list if used as function parameter
int list_function_parameter(std::list<int> l){
    for(std::list<int>::iterator itr=l.begin();itr!=l.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<l.size()<<"  "<<l.capacity()<<std::endl;
    l.pop_back();
}
// list if used as function return value
std::list<int> list_function_return_value(){
    std::list<int> l;
    l.push_back(8);
    l.push_back(0);
    l.push_back(0);
    l.push_back(8);
    return l;
}
// list if used as pointer parameter
int list_pointer_parameter(std::list<int> *l){
    for(std::list<int>::iterator itr=l->begin();itr!=l->end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<l->size()<<"  "<<l->capacity()<<std::endl;
    l->pop_back();
}

int main(){
    list_variable();
    return 0;
}

