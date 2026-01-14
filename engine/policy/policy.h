#ifndef POLICY_H
#define POLICY_H

#include "../common/engine_types.h"

// Policy interface
int policy_check(const ble_event_t *event);

#endif
