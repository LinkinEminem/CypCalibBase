#include "TrackerFactory.h"

ILaserTracker* TrackerFactory::CreateTracker(const int brand)
{
    switch (brand)
    {
    case 0:
        {
            return new apicore::TAPICore();
            break;
        }
    case 1:
        {
            return new apipro::TAPIPro();
            break;
        }
    default:
        {
            return nullptr;
        }
    }
}
