#include "rule_engine.h"

float rule_evaluate(const ble_event_t *event) {
    // Dummy rule: block if RSSI < -80
    return (event->rssi < -80) ? 1.5f : 0.2f;
}
