//
// Created by Chandler Pope on 09/01/2026.
//

#include "wwise_c_api.h"
#include <AK/Plugin/AllPluginsFactories.h>

#include "core/utils.h"
#include "godot_cpp/variant/variant.hpp"

uint64_t RegisterGameObject(uint64_t game_object_id) {
    //AkGameObjectID id = get_ak_game_object_id(game_object);
    AKRESULT result = AK::SoundEngine::RegisterGameObj(game_object_id);
    //post_register_game_object(result, game_object, id);
    return ERROR_CHECK_MSG(
            result, godot::vformat("WwiseGodot: Failed to register Game Object with name: %s.", game_object_id));
}

uint64_t UnregisterGameObject(uint64_t game_object_id) {
    AKRESULT result = AK::SoundEngine::UnregisterGameObj(game_object_id);
    return ERROR_CHECK_MSG(result, "WwiseGodot: Failed to unregister Game Object.");
}

AkPlayingID PostEvent(uint32_t event_id, uint64_t game_object_id) {
    AkPlayingID playing_id = AK::SoundEngine::PostEvent(event_id, game_object_id);

    if (playing_id == AK_INVALID_PLAYING_ID)
    {
        ERROR_CHECK_MSG(AK_InvalidID,
                        godot::vformat("Failed to post Event: %d on Game Object: %s.", event_id, game_object_id));
    }

    return playing_id;
}

bool SetPosition(uint64_t game_object_id, const Transform3D& transform_3d) {
    AkSoundPosition sound_pos{};
    godot_transform3d_to_ak_sound_position(transform_3d, sound_pos);

    return ERROR_CHECK(AK::SoundEngine::SetPosition(game_object_id, sound_pos));
}