#ifndef msDesktopBuilder_hpp
#define msDesktopBuilder_hpp

#include "desktopBuilder.hpp"

class msDesktopBuilder:public DesktopBuilder{
    public:
        msDesktopBuilder();
        void buildMonitor();
        void buildKeyboard();
        void buildMouse();
        void buildSpeaker();
        void buildHarddisk();
        void buildCpu();
        void buildRam();
        Desktop* getDesktop();
};

#endif