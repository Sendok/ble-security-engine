#include "engine_api.h"

#include "../common/engine_log.h"
#include "../feature_engine/feature_extractor.h"
#include "../feature_engine/session_state.h"

#include "../security_engine/rule_engine.h"
#include "../security_engine/anomaly_engine.h"
#include "../security_engine/decision_engine.h"
#include "../ai_engine/ai_plugin.h"





static int engine_initialized = 0;
static ble_session_state_t session;
static int session_active = 0;
void ai_builtin_model_init(void);

void engine_init(void)
{
    if (engine_initialized)
        return;

    ENGINE_LOG("INFO", "Engine initialized");

    #if ENGINE_AI_ENABLED
        ai_builtin_model_init();
    #endif

    engine_initialized = 1;
}

security_decision_t engine_process_event(const ble_event_t *event)
{
    if (!engine_initialized)
    {
        engine_init();
    }

    /* Handle session lifecycle */
    if (event->type == BLE_EVT_CONNECT)
    {
        session_reset(&session, event->timestamp);
        session_active = 1;
    }
    else if (event->type == BLE_EVT_DISCONNECT)
    {
        session_active = 0;
        ENGINE_LOG("INFO", "Session closed");
    }

    if (!session_active)
    {
        /* No active session: safe default */
        security_decision_t d = { 0.0f, ACTION_ALLOW };
        return d;
    }

    session_update(&session, event);

    /* Rule evaluation */
    float rule_score = rule_evaluate(event);
    /* Feature-aware anomaly */
    ble_feature_t feat = extract_features(event, &session);
    float anomaly = anomaly_score(feat.write_rate, 0.01f, 0.02f);

    /* Rule evaluation */
    float rule_score = rule_evaluate(event);

    /* Feature-aware anomaly */
    ble_feature_t feat = extract_features(event, &session);
    float anomaly = anomaly_score(feat.write_rate, 0.01f, 0.02f);

    /* AI advisory (optional) */
    float ai_score = ai_plugin_infer(&feat, event);

    /* Combine */
    float final_anomaly = anomaly;
    if (ai_score >= 0.0f)
    {
        final_anomaly = (anomaly + ai_score) * 0.5f;
        ENGINE_LOG("AI", "AI score=%.2f combined anomaly=%.2f",
                ai_score, final_anomaly);
    }

    return engine_decide(rule_score, final_anomaly);

}


