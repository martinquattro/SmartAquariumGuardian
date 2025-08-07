#include "smart_aquarium_guardian.h"

extern "C" void app_main(void) 
{
    SmartAquariumGuardian::Init();

    while (true) 
    {
        SmartAquariumGuardian::GetInstance()->Update();
    }
}