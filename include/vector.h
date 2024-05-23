#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <stdexcept>

class vec3 {
    private:
        float x, y, z;
    public:
        vec3(float x, float y, float z);

        // Overload the [] operator to allow for array-like access
        float& operator[](int index);

        // Overload the math operators to allow for vector math
        vec3 operator+(vec3 other);
        vec3 operator-(vec3 other);
        vec3 operator*(float scalar);
        vec3 operator/(float scalar);

        // Overload the comparison operators to allow for vector comparison
        bool operator==(vec3 other);
        bool operator!=(vec3 other);

        float dot(vec3 other);
        vec3 cross(vec3 other);
        float magnitude();
        vec3 normalize();
        float angle(vec3 other);
};

class vec2 {
    private:
        float x, y;
    public:
        vec2(float x, float y);

        // Overload the [] operator to allow for array-like access
        float& operator[](int index);

        // Overload the math operators to allow for vector math
        vec2 operator+(vec2 other);
        vec2 operator-(vec2 other);
        vec2 operator*(float scalar);
        vec2 operator/(float scalar);

        // Overload the comparison operators to allow for vector comparison
        bool operator==(vec2 other);
        bool operator!=(vec2 other);

        float dot(vec2 other);
        vec3 cross(vec2 other);
        float magnitude();
        vec2 normalize();
        float angle(vec2 other);
};

#endif