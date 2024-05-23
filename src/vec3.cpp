#include "vector.h"

// Constructor

vec3::vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Operator overloads

float& vec3::operator[](int index) {
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::out_of_range("Index out of range");
    }
}

vec3 vec3::operator+(vec3 other) {
    return vec3(x + other.x, y + other.y, z + other.z);
}

vec3 vec3::operator-(vec3 other) {
    return vec3(x - other.x, y - other.y, z - other.z);
}

vec3 vec3::operator*(float scalar) {
    return vec3(x * scalar, y * scalar, z * scalar);
}

vec3 vec3::operator/(float scalar) {
    return vec3(x / scalar, y / scalar, z / scalar);
}

bool vec3::operator==(vec3 other) {
    return x == other.x && y == other.y && z == other.z;
}

bool vec3::operator!=(vec3 other) {
    return x != other.x || y != other.y || z != other.z;
}

// Vector math functions

float vec3::dot(vec3 other) {
    return x * other.x + y * other.y + z * other.z;
}

vec3 vec3::cross(vec3 other) {
    return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float vec3::magnitude() {
    return sqrt(x * x + y * y + z * z);
}

vec3 vec3::normalize() {
    return *this / magnitude();
}

float vec3::angle(vec3 other) {
    return acos(dot(other) / (magnitude() * other.magnitude()));
}
