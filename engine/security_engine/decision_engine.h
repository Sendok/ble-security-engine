#ifndef DECISION_ENGINE_H
#define DECISION_ENGINE_H

#include "../common/engine_types.h"

security_decision_t engine_decide(float rule_score, float anomaly);

#endif
