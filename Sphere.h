#pragma once
#include "utils.h"

class Sphere : public Hittable{
    public:
    Vec3 center;
    float radius;
    std::shared_ptr<Material> material;
    Sphere(){}
    Sphere(Vec3 cen,float r,std::shared_ptr<Material> mat) :
        center(cen),radius(r),material(mat){}
    virtual bool hit(const Ray& r,float t_min,float t_max,hit_record& rec) const override;
};
