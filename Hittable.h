#pragma once
#include "Vec3.h"
#include "Ray.h"


struct hit_record{
    Vec3 p; //hit point
    Vec3 normal; //surface view direction
    float t; // dist from camera to hit point
};

class Hittable {
    public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& r,float t_min,float t_max,hit_record& rec) const = 0;
};