//
// Created by Chandler Pope on 09/01/2026.
//

#pragma once
#include <stdint.h>
#include "godot_cpp/variant/transform3d.hpp"

using namespace godot;

#if defined(__APPLE__)
    #define WWISE_C_API extern "C" __attribute__((visibility("default"))) __attribute__((used))
#elif defined(_WIN32)
    #define WWISE_C_API extern "C" __declspec(dllexport)
#else
    #define WWISE_C_API extern "C" __attribute__((visibility("default")))
#endif

WWISE_C_API uint64_t RegisterGameObject(uint64_t game_object_id);
WWISE_C_API uint64_t UnregisterGameObject(uint64_t game_object_id);

WWISE_C_API AkPlayingID PostEvent(uint32_t event_id, uint64_t game_object_id);

WWISE_C_API bool SetPosition(uint64_t game_object_id, const Transform3D& transform_3d);