#include "ble_adapter.h"
#include "../common/engine_log.h"

void ble_adapter_send(const ble_event_t *event) {
    ENGINE_LOG("ADAPTER", "Send event type %d", event->type);
}
