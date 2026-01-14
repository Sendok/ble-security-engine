#include "feature_extractor.h"
#include "session_state.h"

ble_feature_t extract_features(
    const ble_event_t *evt,
    const ble_session_state_t *session
)
{
    ble_feature_t f;

    uint32_t duration = evt->timestamp - session->session_start_ts;
    if (duration == 0) duration = 1;

    f.avg_rssi = (float)session->last_rssi;
    f.write_rate = (float)session->write_count / duration;
    f.session_duration = (float)duration;

    return f;
}
