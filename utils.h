#pragma once
#include "HittableList.h"
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

inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

inline Vec3 random_in_unit_sphere(){
    while(true){
        Vec3 p(random_float()*2.0f -1.0f,
                random_float()*2.0f-1.0f,
                random_float()*2.0f-1.0f);
        if(p.length_squared()<1.0f) return p;
    }
}

inline Vec3 random_unit_vector(){
    return unit_vector(random_in_unit_sphere());
}

inline Vec3 reflect(const Vec3& v,const Vec3& n){
    return v-n*(2.0f*dot(v,n));
}

Vec3 ray_color(const Ray& r,const Hittable& world,int depth);