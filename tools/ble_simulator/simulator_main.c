#include "../../engine/api/engine_api.h"
#include <stdio.h>

// int main()
// {
//     engine_init();
//     ble_event_t evt = {
//         .type = BLE_EVT_WRITE,
//         .timestamp = 1000,
//         .rssi = -85,
//         .char_uuid = 0xFFFF,
//         .payload_len = 128
//     };
//     security_decision_t d = engine_process_event(&evt);
//     printf("Decision: %d\n", d.action);
//     return 0;
// }
#include "attack_profile.h"

void replay_profile(const attack_profile_t *profile);

int main(int argc, char **argv)
{
    engine_init();

    const char *name = (argc > 1) ? argv[1] : "write_flood";
    const attack_profile_t *p = get_attack_profile(name);

    if (!p)
    {
        printf("Unknown profile: %s\n", name);
        return 1;
    }

    replay_profile(p);
    return 0;
}
