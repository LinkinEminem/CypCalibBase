#pragma once

#ifdef LASERENGINE_EXPORTS
    #define LASER_ENGINE_API           __declspec(dllexport)
    #define LASER_ENGINE_API_EXTERN    __declspec(dllexport) extern
    #define LASER_ENGINE_API_EXTERNC   extern "C" __declspec(dllexport)
#else
    #define LASER_ENGINE_API           __declspec(dllimport)
    #define LASER_ENGINE_API_EXTERN    __declspec(dllimport) extern
    #define LASER_ENGINE_API_EXTERNC   extern "C" __declspec(dllimport)
#endif
