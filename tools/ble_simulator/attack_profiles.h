#ifndef ATTACK_PROFILE_H
#define ATTACK_PROFILE_H

#include "../../engine/common/engine_types.h"

typedef struct {
    const char *name;
    const ble_event_t *events;
    int event_count;
} attack_profile_t;

const attack_profile_t* get_attack_profile(const char *name);

#endif
