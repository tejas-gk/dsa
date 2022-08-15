#include<iostream>
#include<map>

// map is a collection of key-value pairs
// map if used as variable
int map_variable(){
    std::map<int,int> m;
    m[8]=8;
    m[0]=0;
    m[0]=0;
    m[8]=8;
    for(std::map<int,int>::iterator itr=m.begin();itr!=m.end();++itr)  {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
    std::cout<<"   "<<m.size()<<std::endl;
    m.erase(8);
    for(std::map<int,int>::iterator itr=m.begin();itr!=m.end();++itr)  {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
}
int main(){
    map_variable();
}