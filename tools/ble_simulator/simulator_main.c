#include "../../engine/api/engine_api.h"
#include <stdio.h>

int main()
{
    engine_init();
    ble_event_t evt = { BLE_EVT_WRITE, 1234, -40, 0x002A, 20 };
    security_decision_t d = engine_process_event(&evt);
    printf("Decision: %d\n", d.action);
    return 0;
}
