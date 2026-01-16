#include "attack_profile.h"

static const ble_event_t replay_write_flood[] = {
    { BLE_EVT_CONNECT,    0,   -45, 0x0000, 0 },
    { BLE_EVT_WRITE,     10,   -48, 0x002A, 20 },
    { BLE_EVT_WRITE,     20,   -47, 0x002A, 20 },
    { BLE_EVT_WRITE,     30,   -46, 0x002A, 20 },
    { BLE_EVT_WRITE,     40,   -46, 0x002A, 20 },
    { BLE_EVT_WRITE,     50,   -46, 0x002A, 20 },
    { BLE_EVT_WRITE,     60,   -46, 0x002A, 20 },
    { BLE_EVT_WRITE,     70,   -46, 0x002A, 20 },
};

static const attack_profile_t profiles[] = {
    {
        .name = "write_flood",
        .events = replay_write_flood,
        .event_count = sizeof(replay_write_flood) / sizeof(ble_event_t)
    }
};

const attack_profile_t* get_attack_profile(const char *name)
{
    for (unsigned i = 0; i < sizeof(profiles)/sizeof(profiles[0]); i++)
    {
        if (!strcmp(profiles[i].name, name))
            return &profiles[i];
    }
    return 0;
}
