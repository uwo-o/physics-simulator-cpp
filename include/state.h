#ifndef STATE_H
#define STATE_H

#include "vector.h"

struct state {
    vec3 pos;
    vec3 vel;
    vec3 acc;
    float mass;
}

#endif