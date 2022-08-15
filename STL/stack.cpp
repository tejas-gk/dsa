#include<iostream>
#include<set>

// set is a collection of unique elements
// set if used as variable
int set_variable(){
    std::set<int> s;
    s.insert(8);
    s.insert(0);
    s.insert(0);
    s.insert(8);
    for(std::set<int>::iterator itr=s.begin();itr!=s.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<s.size()<<std::endl;
    s.erase(8);
    for(std::set<int>::iterator itr=s.begin();itr!=s.end();++itr)  {
        std::cout<<*itr;
    }
}

int main(){
    set_variable();
}