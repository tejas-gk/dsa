#include "dellDesktopBuilder.hpp"

void dellDesktopBuilder::buildMonitor() {
    desktop->setMonitor("Dell Monitor");
}
void dellDesktopBuilder::buildKeyboard() {
    desktop->setKeyboard("Dell Keyboard");
}
void dellDesktopBuilder::buildMouse() {
    desktop->setMouse("Dell Mouse");
}
void dellDesktopBuilder::buildSpeaker() {
    desktop->setSpeaker("Dell Speaker");
}
void dellDesktopBuilder::buildHarddisk() {
    desktop->setHarddisk("Dell Harddisk");
}
void dellDesktopBuilder::buildCpu() {
    desktop->setCpu("Dell CPU");
}
void dellDesktopBuilder::buildRam() {
    desktop->setRam("Dell RAM");
}
Desktop* dellDesktopBuilder::getDesktop() {
    return desktop;
}