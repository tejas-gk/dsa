#include<iostream>
#include<list>
class Subscriber{
public:
    virtual void notify(std::string message) = 0;
};
class User:public Subscriber{
    private:
    int user_id;
    public:
    User(int id):user_id(id){}
    void notify(std::string message){
        std::cout<<"User "<<user_id<<" received message: "<<message<<std::endl;
    }

};
class Group{
    private:
    std::list<Subscriber*> subscribers;
    public:
    void add_subscriber(Subscriber* subscriber){
        subscribers.push_back(subscriber);
    }
    void remove_subscriber(Subscriber* subscriber){
        subscribers.remove(subscriber);
    }
    void notify(std::string message){
        for(auto subscriber:subscribers){
            subscriber->notify(message);
        }
    }

};


int main(){
    Group *group = new Group();
    User *user1 = new User(1);
    User *user2 = new User(2);
    group->add_subscriber(user1);
    group->add_subscriber(user2);
    group->notify("Hello");
    
    group->remove_subscriber(user1);
    group->notify("Hello");

    
}
