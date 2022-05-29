#ifndef desktop_hpp
#define desktop_hpp

#include<string>
using namespace std;

class Desktop {
private:
   string monitor,keyboard,mouse,speaker,harddisk,cpu,ram;
public:
//setters
    Desktop();
    void setMonitor(string monitor);
    void setKeyboard(string keyboard);
    void setMouse(string mouse);
    void setSpeaker(string speaker);
    void setHarddisk(string harddisk);
    void setCpu(string cpu);
    void setRam(string ram);
    //getters
    string getMonitor();
    string getKeyboard();
    string getMouse();
    string getSpeaker();
    string getHarddisk();
    string getCpu();
    string getRam();
    void showSpecs();

};
#endif /* desktop_hpp */