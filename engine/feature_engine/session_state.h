#ifndef SESSION_STATE_H
#define SESSION_STATE_H

#include "../common/engine_types.h"

typedef struct {
    uint32_t session_start_ts;
    uint32_t last_event_ts;
    uint16_t write_count;
    uint16_t read_count;
    int8_t   last_rssi;
} ble_session_state_t;

void session_reset(ble_session_state_t *s, uint32_t ts);
void session_update(ble_session_state_t *s, const ble_event_t *evt);

#endif
