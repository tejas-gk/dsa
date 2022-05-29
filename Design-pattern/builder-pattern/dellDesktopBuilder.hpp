#ifndef dellDesktopBuilder_hpp
#define dellDesktopBuilder_hpp

#include "desktopBuilder.hpp"

class dellDesktopBuilder:public DesktopBuilder{
    public:
        // dellDesktopBuilder();
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