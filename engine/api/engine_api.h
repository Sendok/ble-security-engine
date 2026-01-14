#ifndef ENGINE_API_H
#define ENGINE_API_H

#include "../common/engine_types.h"

void engine_init(void);
security_decision_t engine_process_event(const ble_event_t *event);

#endif
