#include<iostream>
#include "desktop.hpp"

void Desktop::setMonitor(string pmonitor) {
    monitor = pmonitor;
}
void Desktop::setKeyboard(string pkeyboard) {
    keyboard = pkeyboard;
}
void Desktop::setMouse(string pmouse) {
    mouse = pmouse;
}
void Desktop::setSpeaker(string pspeaker) {
    speaker = pspeaker;
}
void Desktop::setHarddisk(string pharddisk) {
    harddisk = pharddisk;
}
void Desktop::setCpu(string pcpu) {
    cpu = pcpu;
}
void Desktop::setRam(string pram) {
    ram = pram;
}
void Desktop::showSpecs() {
    cout << "Monitor: " << monitor << endl;
    cout << "Keyboard: " << keyboard << endl;
    cout << "Mouse: " << mouse << endl;
    cout << "Speaker: " << speaker << endl;
    cout << "Harddisk: " << harddisk << endl;
    cout << "CPU: " << cpu << endl;
    cout << "RAM: " << ram << endl;
}
