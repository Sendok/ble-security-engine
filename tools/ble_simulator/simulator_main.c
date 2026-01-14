#include "../../engine/api/engine_api.h"
#include <stdio.h>

int main()
{
    engine_init();
    ble_event_t evt = {
        .type = BLE_EVT_WRITE,
        .timestamp = 1000,
        .rssi = -85,
        .char_uuid = 0xFFFF,
        .payload_len = 128
    };
    security_decision_t d = engine_process_event(&evt);
    printf("Decision: %d\n", d.action);
    return 0;
}
