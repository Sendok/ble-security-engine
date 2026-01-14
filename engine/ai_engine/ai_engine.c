#include "ai_plugin.h"
#include "../common/engine_log.h"

static ai_infer_fn ai_fn = 0;

void ai_plugin_register(ai_infer_fn fn)
{
    ai_fn = fn;
    ENGINE_LOG("INFO", "AI plugin registered");
}

float ai_plugin_infer(const ble_feature_t *features,
                      const ble_event_t *event)
{
    if (!ai_fn)
        return -1.0f;

    float score = ai_fn(features, event);

    if (score < 0.0f || score > 1.0f)
    {
        ENGINE_LOG("WARN", "AI returned invalid score");
        return -1.0f;
    }

    return score;
}
