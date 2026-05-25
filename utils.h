#pragma once
#include "Vec3.h"
#include "Ray.h"

inline Vec3 operator*(float s,const Vec3& v){
    return v*s;
}

inline float dot(const Vec3& u,const Vec3&v){
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

inline Vec3 unit_vector(Vec3 v){
    return v/v.length();
}

Vec3 ray_color(const Ray& r);

float hit_sphere(const Vec3& center, float radius,const Ray& r);