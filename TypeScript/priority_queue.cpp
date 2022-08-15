#include<iostream>
#include<priority_queue>

// priority_queue is a collection of elements
// priority_queue if used as variable
int priority_queue_variable(){
    std::priority_queue<int> pq;
    pq.push(8);
    pq.push(0);
    pq.push(0);
    pq.push(8);
    for(std::priority_queue<int>::iterator itr=pq.begin();itr!=pq.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<pq.size()<<std::endl;
    pq.pop();
    for(std::priority_queue<int>::iterator itr=pq.begin();itr!=pq.end();++itr)  {
        std::cout<<*itr;
    }
}
int main(){
    priority_queue_variable();
}
