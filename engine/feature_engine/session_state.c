#include "session_state.h"
#include <string.h>

void session_reset(ble_session_state_t *s, uint32_t ts)
{
    memset(s, 0, sizeof(*s));
    s->session_start_ts = ts;
    s->last_event_ts = ts;
}

void session_update(ble_session_state_t *s, const ble_event_t *evt)
{
    s->last_event_ts = evt->timestamp;
    s->last_rssi = evt->rssi;

    if (evt->type == BLE_EVT_WRITE)
        s->write_count++;

    if (evt->type == BLE_EVT_READ)
        s->read_count++;
}
