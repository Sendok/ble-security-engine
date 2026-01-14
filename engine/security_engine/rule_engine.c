#include "rule_engine.h"
#include "../common/engine_log.h"

/*
 Rule definitions:

 R1: Weak RSSI + WRITE command
 R2: Large payload write (possible injection)
 R3: Unknown / reserved characteristic UUID
 R4: Suspicious reconnect (weak RSSI on connect)
 R5: Abnormally strong RSSI (relay / spoof indication)
*/

float rule_evaluate(const ble_event_t *event)
{
    float risk = 0.0f;

    /* R1: Weak RSSI but WRITE command */
    if (event->type == BLE_EVT_WRITE && event->rssi < -80)
    {
        ENGINE_LOG("WARN", "R1 triggered: weak RSSI write");
        risk += 0.30f;
    }

    /* R2: Large payload injection */
    if (event->type == BLE_EVT_WRITE && event->payload_len > 64)
    {
        ENGINE_LOG("WARN", "R2 triggered: large payload");
        risk += 0.25f;
    }

    /* R3: Unknown characteristic UUID */
    if (event->char_uuid == 0xFFFF)
    {
        ENGINE_LOG("WARN", "R3 triggered: unknown characteristic");
        risk += 0.20f;
    }

    /* R4: Suspicious reconnect (low RSSI connect) */
    if (event->type == BLE_EVT_CONNECT && event->rssi < -90)
    {
        ENGINE_LOG("WARN", "R4 triggered: suspicious reconnect");
        risk += 0.15f;
    }

    /* R5: Abnormally strong RSSI */
    if (event->rssi > -5)
    {
        ENGINE_LOG("WARN", "R5 triggered: abnormally strong RSSI");
        risk += 0.20f;
    }

    /* Clamp */
    if (risk > 1.0f)
        risk = 1.0f;

    return risk;
}
