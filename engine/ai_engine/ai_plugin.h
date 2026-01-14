#ifndef AI_PLUGIN_H
#define AI_PLUGIN_H

#include "../common/engine_types.h"
#include "../feature_engine/feature_schema.h"

/*
 AI plugin interface.
 Return value:
  -1.0f  : AI abstain / not available
  0.0-1.0: AI risk score
*/
typedef float (*ai_infer_fn)(
    const ble_feature_t *features,
    const ble_event_t   *event
);

void ai_plugin_register(ai_infer_fn fn);
float ai_plugin_infer(const ble_feature_t *features,
                      const ble_event_t *event);

#endif
