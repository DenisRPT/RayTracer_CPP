#include "Sphere.h"

bool Sphere::hit(const Ray& r,float t_min,float t_max,hit_record& rec) const{
    Vec3 oc = r.origin()-center;
    float a = dot(r.direction(),r.direction());
    float b = 2.0f* dot(oc,r.direction());
    float c = dot(oc,oc)-radius*radius;
    float discriminant = b*b-4*a*c;
    if(discriminant<0){
        return false;
    }
    float root = (-b - std::sqrt(discriminant))/(2.0f*a);
    if(root < t_min || root>t_max){
        root = (-b+std::sqrt(discriminant))/(2.0f*a);
        if(root <t_min || root>t_max){
            return false;
        }
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p-center)/radius;
    return true;
}