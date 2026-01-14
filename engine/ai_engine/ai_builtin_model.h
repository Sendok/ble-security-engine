#include "ai_plugin.h"
#include "ai_model_stats.h"
#include "../common/engine_log.h"

static ai_stat_model_t write_rate_model;

static float builtin_ai_infer(
    const ble_feature_t *f,
    const ble_event_t *e
)
{
    (void)e;

    ai_model_update(&write_rate_model, f->write_rate);
    float score = ai_model_score(&write_rate_model, f->write_rate);

    ENGINE_LOG("AI", "write_rate=%.4f mean=%.4f score=%.2f",
               f->write_rate,
               write_rate_model.mean,
               score);

    return score;
}

void ai_builtin_model_init(void)
{
    ai_model_init(&write_rate_model, 0.05f);
    ai_plugin_register(builtin_ai_infer);
}
