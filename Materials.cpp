#include "Materials.h"

bool Lambertian::scatter(const Ray& r, const hit_record& rec,Vec3& attenuation,Ray& scattered) const{
    Vec3 scatter_direction = rec.normal+random_unit_vector();
    scattered = Ray(rec.p,scatter_direction);
    attenuation = albedo;
    return true;
 }

bool Metal::scatter(const Ray& r, const hit_record& rec,Vec3& attenuation,Ray& scattered) const{
    Vec3 reflected = reflect(unit_vector(r.direction()),rec.normal);
    scattered = Ray(rec.p,reflected+random_unit_vector()*fuzz);
    attenuation = albedo;
    return dot(scattered.direction(),rec.normal)>0.0f;
 }