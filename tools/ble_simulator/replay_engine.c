#include "attack_profile.h"
#include "../../engine/api/engine_api.h"
#include <stdio.h>

void replay_profile(const attack_profile_t *profile)
{
    printf("=== Replaying attack: %s ===\n", profile->name);

    for (int i = 0; i < profile->event_count; i++)
    {
        const ble_event_t *evt = &profile->events[i];
        security_decision_t d = engine_process_event(evt);

        printf("t=%u evt=%d rssi=%d action=%d\n",
               evt->timestamp,
               evt->type,
               evt->rssi,
               d.action);
    }
}
