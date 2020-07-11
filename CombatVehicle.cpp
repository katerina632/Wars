#include "CombatVehicle.h"

bool Round(CombatVehicle& bm1, CombatVehicle& bm2)
{        
    do {       
        bm2.Defense(bm1.Attack());
        if (bm2.IsDestroyed())
            return true;
       
        bm1.Defense(bm2.Attack());
        if (bm1.IsDestroyed())
            return false;
    } while (!bm2.IsDestroyed() && !bm1.IsDestroyed());
}





