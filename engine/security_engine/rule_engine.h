#ifndef RULE_ENGINE_H
#define RULE_ENGINE_H

#include "../common/engine_types.h"

/*
 Rule Engine v1
 Evaluates BLE events and returns risk score [0.0 - 1.0]
*/
float rule_evaluate(const ble_event_t *event);

#endif
