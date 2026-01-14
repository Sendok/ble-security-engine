#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#include <stdint.h>

typedef enum {
    BLE_EVT_CONNECT,
    BLE_EVT_DISCONNECT,
    BLE_EVT_READ,
    BLE_EVT_WRITE,
    BLE_EVT_RSSI
} ble_event_type_t;

typedef struct {
    ble_event_type_t type;
    uint32_t timestamp;
    int8_t rssi;
    uint16_t char_uuid;
    uint16_t payload_len;
} ble_event_t;

typedef enum {
    ACTION_ALLOW,
    ACTION_LIMIT,
    ACTION_BLOCK
} security_action_t;

typedef struct {
    float risk_score;
    security_action_t action;
} security_decision_t;

#endif
