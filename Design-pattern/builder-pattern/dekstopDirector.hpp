#ifndef desktopDirector_hpp
#define desktopDirector_hpp

#include "desktopBuilder.hpp"

class DesktopDirector {
private:
    DesktopBuilder* desktopBuilder;
public:
    DesktopDirector(DesktopBuilder* pdesktopBuilder){
        desktopBuilder = pdesktopBuilder;
    }
    Desktop *buildDesktop(){
        desktopBuilder->buildMonitor();
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMouse();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildHarddisk();
        desktopBuilder->buildCpu();
        desktopBuilder->buildRam();
        return desktopBuilder->getDesktop();
    }
  
    Desktop* getDesktop(){
        return desktopBuilder->getDesktop();
    }
};
#endif /* desktopDirector_hpp */