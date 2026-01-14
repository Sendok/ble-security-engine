#include "anomaly_engine.h"#include "anomaly_engine.h"







}    return (z > 2.0f || z < -2.0f) ? 1.0f : 0.0f;    float z = (value - mean) / stddev;    if (stddev == 0) return 0.0f;float anomaly_score(float value, float mean, float stddev) {
float anomaly_score(float value, float mean, float stddev) {
    if (stddev == 0) return 0.0f;
    float z = (value - mean) / stddev;
    return (z > 2.0f || z < -2.0f) ? 1.0f : 0.0f;
}
