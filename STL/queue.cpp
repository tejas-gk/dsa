#include<iostream>
#include<queue>
#include<iterator>
// queue is a container adaptor that implements a queue.
// queue if used as variable
int queue_variable(){
    std::queue<int> q;
    q.push(8);
    q.push(0);
    q.push(0);
    q.push(8);
    q.push(0);
    q.pop();
    for(std::queue<int>::iterator itr=q.begin();itr!=q.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<q.size()<<std::endl;
    q.pop();
    for(std::queue<int>::iterator itr=q.begin();itr!=q.end();++itr)  {
        std::cout<<*itr;
    }
}
int main(){
    queue_variable();
}