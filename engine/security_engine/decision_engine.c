#include "rule_engine.h"
#include "anomaly_engine.h"
#include "../common/engine_log.h"

security_decision_t engine_decide(float rule_score, float anomaly)
{
    security_decision_t d;
    d.risk_score = rule_score + anomaly;
    d.action = (d.risk_score > 1.0f) ? ACTION_BLOCK : ACTION_ALLOW;
    ENGINE_LOG("INFO", "Risk=%.2f", d.risk_score);
    return d;
}
