#include<iostream>
#include<unordered_set>
#include<unordered_map>

// unordered_set is a collection of unique elements
// unordered_set if used as variable
int unordered_set_variable(){
    std::unordered_set<int> s;
    s.insert(8);
    s.insert(0);
    s.insert(0);
    s.insert(8);
    for(std::unordered_set<int>::iterator itr=s.begin();itr!=s.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<s.size()<<std::endl;
    s.erase(8);
    for(std::unordered_set<int>::iterator itr=s.begin();itr!=s.end();++itr)  {
        std::cout<<*itr;
    }
}
// unordered_map is a collection of key-value pairs
int unordered_map_variable(){
    std::unordered_map<int,int> m;
    m[8]=8;
    m[0]=0;
    m[0]=0;
    m[8]=8;
    for(std::unordered_map<int,int>::iterator itr=m.begin();itr!=m.end();++itr)  {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
    std::cout<<"   "<<m.size()<<std::endl;
    m.erase(8);
    for(std::unordered_map<int,int>::iterator itr=m.begin();itr!=m.end();++itr)  {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
}

int main(){
    unordered_set_variable();
    unordered_map_variable();
}
