#include "policy.h"
#include "../common/engine_log.h"

int policy_check(const ble_event_t *event) {
    ENGINE_LOG("POLICY", "Checking event type %d", event->type);
    return 0;
}
