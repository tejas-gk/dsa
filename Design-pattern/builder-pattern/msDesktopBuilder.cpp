#include "msDesktopBuilder.hpp"

void msDesktopBuilder::buildMonitor() {
    desktop->setMonitor("ms Monitor");
}
void msDesktopBuilder::buildKeyboard() {
    desktop->setKeyboard("ms Keyboard");
}
void msDesktopBuilder::buildMouse() {
    desktop->setMouse("ms Mouse");
}
void msDesktopBuilder::buildSpeaker() {
    desktop->setSpeaker("ms Speaker");
}
void msDesktopBuilder::buildHarddisk() {
    desktop->setHarddisk("ms Harddisk");
}
void msDesktopBuilder::buildCpu() {
    desktop->setCpu("ms CPU");
}
void msDesktopBuilder::buildRam() {
    desktop->setRam("ms RAM");
}
Desktop* msDesktopBuilder::getDesktop() {
    return desktop;
}