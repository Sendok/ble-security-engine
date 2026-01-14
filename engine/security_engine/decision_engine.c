#include "decision_engine.h"
#include "../common/engine_log.h"

/*
 Decision thresholds:
  - < 0.4  : allow
  - < 0.7  : rate limit
  - >= 0.7 : block
*/

security_decision_t engine_decide(float rule_score, float anomaly)
{
    security_decision_t d;

    d.risk_score = rule_score + anomaly;
    if (d.risk_score > 1.0f)
        d.risk_score = 1.0f;

    if (d.risk_score < 0.4f)
        d.action = ACTION_ALLOW;
    else if (d.risk_score < 0.7f)
        d.action = ACTION_LIMIT;
    else
        d.action = ACTION_BLOCK;

    ENGINE_LOG(
        "DECISION",
        "risk=%.2f rule=%.2f anomaly=%.2f action=%d",
        d.risk_score, rule_score, anomaly, d.action
    );

    return d;
}
