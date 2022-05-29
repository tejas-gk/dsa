#include "dellDesktopBuilder.hpp"
#include "msDesktopBuilder.hpp"
#include "dekstopDirector.hpp"

int main() {
    DesktopDirector* dellDirector = new DesktopDirector(new dellDesktopBuilder());
    dellDirector->buildDesktop();
    Desktop* dellDesktop = dellDirector->getDesktop();
    dellDesktop->showSpecs();
    delete dellDesktop;
    delete dellDirector;

    DesktopDirector* msDirector = new DesktopDirector(new msDesktopBuilder());
    msDirector->buildDesktop();
    Desktop* msDesktop = msDirector->getDesktop();
    msDesktop->showSpecs();
    delete msDesktop;
    delete msDirector;
    return 0;
}

