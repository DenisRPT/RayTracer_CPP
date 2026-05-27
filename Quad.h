#pragma once
#include "utils.h"

class Quad : public Hittable{
    public:
    Vec3 Q;
    Vec3 u,v;
    Vec3 normal;
    float D;
    Vec3 w;
    std::shared_ptr<Material> material;
    
    Quad(const Vec3& _Q,const Vec3& _u,const Vec3& _v,std::shared_ptr<Material> mat)
        :Q(_Q) ,u(_u), v(_v),material(mat) {
            Vec3 n = cross(u,v);
            normal = unit_vector(n);
            D = dot(normal,Q);
            w = n/dot(n,n);
        }
    virtual bool hit(const Ray& r,float t_min,float t_max,hit_record& rec) const override;

};