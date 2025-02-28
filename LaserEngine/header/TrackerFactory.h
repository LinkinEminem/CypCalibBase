#pragma once

#include "APICore.h"
#include "APIPro.h"
#include "ILaserTracker.h"
#include "EnvDefs.h"

class LASER_ENGINE_API TrackerFactory
{
public:
    static ILaserTracker* CreateTracker(const int brand);
};
