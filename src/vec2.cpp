#include "vector.h"

vec2::vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

float& vec2::operator[](int index) {
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        default:
            throw std::out_of_range("Index out of range");
    }
}


// Operator overloads

vec2 vec2::operator+(vec2 other) {
    return vec2(x + other.x, y + other.y);
}

vec2 vec2::operator-(vec2 other) {
    return vec2(x - other.x, y - other.y);
}

vec2 vec2::operator*(float scalar) {
    return vec2(x * scalar, y * scalar);
}

vec2 vec2::operator/(float scalar) {
    return vec2(x / scalar, y / scalar);
}

// Comparison operators
bool vec2::operator==(vec2 other) {
    return x == other.x && y == other.y;
}

bool vec2::operator!=(vec2 other) {
    return x != other.x || y != other.y;
}

// Vector math functions

float vec2::dot(vec2 other) {
    return x * other.x + y * other.y;
}

vec3 vec2::cross(vec2 other) {
    return vec3(0, 0, x * other.y - y * other.x);
}

float vec2::magnitude() {
    return sqrt(x * x + y * y);
}

vec2 vec2::normalize() {
    return *this / magnitude();
}

float vec2::angle(vec2 other) {
    return acos(dot(other) / (magnitude() * other.magnitude()));
}
