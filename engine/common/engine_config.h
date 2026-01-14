#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H
#define ENGINE_AI_ENABLED 1

#define THRESH_ALLOW_MAX   0.4f
#define THRESH_LIMIT_MAX   0.7f

#endif

#if ENGINE_AI_ENABLED
float ai_score = ai_plugin_infer(&feat, event);
#else
float ai_score = -1.0f;
#endif
