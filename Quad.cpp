#include "Quad.h"

bool Quad::hit(const Ray& r, float t_min,float t_max,hit_record& rec) const{
    float denom = dot(normal,r.direction());
    if(std::abs(denom)<1e-8){
        return false;
    }
    float t = (D-dot(normal,r.origin()))/denom;
    if(t<t_min || t>t_max){
        return false;
    }
    Vec3 p = r.at(t);
    Vec3 planar_hitpt_vector = p-Q;
    float alpha = dot(w,cross(planar_hitpt_vector,v));
    float beta = dot(w,cross(u,planar_hitpt_vector));
    if(alpha < 0.0f|| alpha>1.0f || beta<0.0f || beta>1.0f){
        return false;
    }
    rec.t = t;
    rec.p = p;
    if(dot(r.direction(),normal)>0.0f){
        rec.normal = normal*-1.0f;
    }
    else{
        rec.normal = normal;
    }
    rec.material = material;
    return true;
}