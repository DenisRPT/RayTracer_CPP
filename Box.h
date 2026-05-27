#pragma once
#include "utils.h"
#include "Quad.h"

class Box:public Hittable{
    public:
    HittableList sides;
    Box(const Vec3&a,const Vec3&b,std::shared_ptr<Material> mat);
    virtual bool hit(const Ray&r ,float t_min,float t_max,hit_record& rec) const override;
};