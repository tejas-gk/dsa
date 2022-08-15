#include<vector>
#include<iostream>

// vector is a dynamic array 
// vector used to store data in contiguous memory
// vector if used as variable
int vector_variable(){
    std::vector<int> v;
     v.push_back(8);
    v.push_back(0);
    v.push_back(0);
    v.push_back(8);
   for(std::vector<int>::iterator itr=v.begin();itr!=v.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<v.size()<<"  "<<v.capacity()<<std::endl;
    v.pop_back();

    
}
// vector if used as function parameter
int vector_function_parameter(std::vector<int> v){
    for(std::vector<int>::iterator itr=v.begin();itr!=v.end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<v.size()<<"  "<<v.capacity()<<std::endl;
    v.pop_back();
}
// vector if used as function return value
std::vector<int> vector_function_return_value(){
    std::vector<int> v;
    v.push_back(8);
    v.push_back(0);
    v.push_back(0);
    v.push_back(8);
    return v;
}
// vector if used as pointer parameter
int vector_pointer_parameter(std::vector<int> *v){
    for(std::vector<int>::iterator itr=v->begin();itr!=v->end();++itr)  {
        std::cout<<*itr;
    }
    std::cout<<"   "<<v->size()<<"  "<<v->capacity()<<std::endl;
    v->pop_back();
}
// vector if used as pointer return value
std::vector<int> *vector_pointer_return_value(){
    std::vector<int> *v = new std::vector<int>;
    v->push_back(8);
    v->push_back(0);
    v->push_back(0);
    v->push_back(8);
    return v;
}


int main(){
    vector_variable();
    std::vector<int> v;
    v.push_back(8);
    v.push_back(0);
    v.push_back(0);
    vector_function_parameter(v);
}