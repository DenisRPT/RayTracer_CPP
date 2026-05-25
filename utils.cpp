#include "utils.h"

Vec3 ray_color(const Ray& r){
    Vec3 sphere_center(0.0f,0.0f,-1.0f);
    float t = hit_sphere(sphere_center, 0.5f, r);
    if(t>0.0f){
        Vec3 hit_point = r.at(t);
        Vec3 N = unit_vector(hit_point - sphere_center);
        return 0.5f*Vec3(N.x+1.0f,N.y+1.0f,N.z+1.0f);
    }
    Vec3 unit_direction = unit_vector(r.direction());
    float a = 0.5f*(unit_direction.y + 1.0f);
    return Vec3(1.0f,1.0f,1.0f)*(1.0f-a) + Vec3(0.5f,0.7f,1.0f)*a;
}

float hit_sphere(const Vec3& center, float radius,const Ray& r){
    /* (P-C)*(P-C) = r*r , where P-random sphere point , C-sphere center, r-radix
        but P(t) = A +tB , where A-origin , B-direction
        so (A+tB-C)*(A+tB-C) = r*r
        using a*t*t + b*t + c = 0 =>
        a = B*B , b = 2B*(A-C) , c=(A-C)*(A-C)-r*r
        discriminant = b*b-4*a*c 
        sphere is hit if disciminant>= 0
    */
    Vec3 oc = r.origin()-center;
    float a = dot(r.direction(),r.direction());
    float b = 2.0f* dot(oc,r.direction());
    float c = dot(oc,oc)-radius*radius;
    float discriminant = b*b-4*a*c;
    if(discriminant<0){
        return -1.0f;
    }
    else{
        return (-b-std::sqrt(discriminant))/(2.0f*a);
    }
}