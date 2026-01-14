#ifndef AI_MODEL_STATS_H
#define AI_MODEL_STATS_H

#include "../feature_engine/feature_schema.h"

/*
 Lightweight statistical model
 Tracks running mean & variance
*/

typedef struct {
    float mean;
    float variance;
    float alpha;   /* EWMA factor */
    int   initialized;
} ai_stat_model_t;

void ai_model_init(ai_stat_model_t *m, float alpha);
float ai_model_update(ai_stat_model_t *m, float value);

/* Returns anomaly score [0.0 - 1.0] */
float ai_model_score(ai_stat_model_t *m, float value);

#endif
