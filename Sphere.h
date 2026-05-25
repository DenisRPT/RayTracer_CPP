#pragma once
#include "Hittable.h"
#include "utils.h"

class Sphere : public Hittable{
    public:
    Vec3 center;
    float radius;
    Sphere(){}
    Sphere(Vec3 cen,float r) :
        center(cen),radius(r){}
    virtual bool hit(const Ray& r,float t_min,float t_max,hit_record& rec) const override;
};
