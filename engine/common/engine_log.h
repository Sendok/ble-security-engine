#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H

#include <stdio.h>

#define ENGINE_LOG(level, fmt, ...) \
    printf("[%s] " fmt "\n", level, ##__VA_ARGS__)

#endif
