#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include "feature_schema.h"
#include "../common/engine_types.h"

ble_feature_t extract_features(const ble_event_t *event);

#endif
