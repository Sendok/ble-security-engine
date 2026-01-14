#include "ai_model_stats.h"
#include <math.h>

void ai_model_init(ai_stat_model_t *m, float alpha)
{
    m->mean = 0.0f;
    m->variance = 0.0f;
    m->alpha = alpha;
    m->initialized = 0;
}

float ai_model_update(ai_stat_model_t *m, float value)
{
    if (!m->initialized)
    {
        m->mean = value;
        m->variance = 0.0f;
        m->initialized = 1;
        return 0.0f;
    }

    float diff = value - m->mean;
    m->mean += m->alpha * diff;
    m->variance = (1.0f - m->alpha) * (m->variance + m->alpha * diff * diff);

    return diff;
}

float ai_model_score(ai_stat_model_t *m, float value)
{
    if (!m->initialized || m->variance < 1e-6f)
        return 0.0f;

    float z = fabsf(value - m->mean) / sqrtf(m->variance);

    /* Normalize z-score to 0..1 */
    if (z > 6.0f) z = 6.0f;
    return z / 6.0f;
}
