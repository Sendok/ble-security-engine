#include "engine_api.h"
#include "../feature_engine/feature_extractor.h"
#include "../security_engine/rule_engine.h"
#include "../security_engine/anomaly_engine.h"
#include "../security_engine/decision_engine.h"
#include "../common/engine_log.h"

static int engine_initialized = 0;

void engine_init(void)
{
    if (engine_initialized) return;

    ENGINE_LOG("INFO", "Engine initialized");
    engine_initialized = 1;
}

security_decision_t engine_process_event(const ble_event_t *event)
{
    if (!engine_initialized)
    {
        engine_init();
    }

    float rule_score = rule_evaluate(event);
    float anomaly = anomaly_score((float)event->rssi, -50.0f, 10.0f);

    security_decision_t decision = engine_decide(rule_score, anomaly);

    return decision;
}
