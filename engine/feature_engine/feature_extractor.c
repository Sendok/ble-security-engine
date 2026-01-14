#include "feature_extractor.h"

ble_feature_t extract_features(const ble_event_t *event) {
    ble_feature_t f = {0};
    // Dummy extraction logic
    f.avg_rssi = event->rssi;
    f.write_rate = 1.0f;
    f.session_duration = 10.0f;
    return f;
}
