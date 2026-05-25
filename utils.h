#pragma once
#include "Hittable.h"
#include <random>

inline Vec3 operator*(float s,const Vec3& v){
    return v*s;
}

inline float dot(const Vec3& u,const Vec3&v){
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

inline Vec3 unit_vector(Vec3 v){
    return v/v.length();
}

inline float random_float(){
    static std::uniform_real_distribution<float> distribution(0.0f,1.0f);
    static std::mt19937 generator;
    return distribution(generator);
}
Vec3 ray_color(const Ray& r,const Hittable& world);