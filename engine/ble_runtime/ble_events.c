#include "ble_hooks.h"
#include "../common/engine_log.h"

void ble_on_event(const ble_event_t *event) {
    ENGINE_LOG("EVENT", "Received event type %d", event->type);
}
