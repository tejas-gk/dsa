#include<iostream>
class IButton{
public:
    virtual void press() = 0;

};
class MacButton : public IButton{
public:
    void press(){
        std::cout << "Mac Button pressed" << std::endl;
    }
};
class WinButton : public IButton{
public:
    void press(){
        std::cout << "Win Button pressed" << std::endl;
    }
};
class ITextBox{
public:
    virtual void display() = 0;
};
class MacTextBox : public ITextBox{
public:
    void display(){
        std::cout << "Mac TextBox displayed" << std::endl;
    }
};
class WinTextBox : public ITextBox{
public:
    void display(){
        std::cout << "Win TextBox displayed" << std::endl;
    }
};
class IFactory {
public:
    virtual IButton* createButton() = 0;
    virtual ITextBox* createTextBox() = 0;
};
class MacFactory : public IFactory{
public:
    IButton* createButton(){
        return new MacButton();
    }
    ITextBox* createTextBox(){
        return new MacTextBox();
    }
};
class WinFactory : public IFactory{
public:
    IButton* createButton(){
        return new WinButton();
    }
    ITextBox* createTextBox(){
        return new WinTextBox();
    }
};
class GUIAbstractFactory{
public:
    static IFactory* createFactory(std::string ostype){
        if(ostype == "Mac"){
            return new MacFactory();
        }else if(ostype == "Win"){
            return new WinFactory();
        }else{
            return nullptr;
        }
        // return new MacFactory();
    }
};

int main(){
    std::cout<<"enter your machine os"<<std::endl;
    std::string ostype;
    std::cin>>ostype;
    IFactory* fact =GUIAbstractFactory::createFactory(ostype);
    
    IButton* btn = fact->createButton();
    ITextBox* txt = fact->createTextBox();
    btn->press();
    txt->display();
    
    return 0;
}
