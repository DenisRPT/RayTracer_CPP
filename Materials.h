#pragma once
#include "utils.h"

class Lambertian : public Material{
    public:
    Vec3 albedo;
    Lambertian(const Vec3& color)
        : albedo(color){}
    virtual bool scatter(const Ray& r, const hit_record& rec,Vec3& attenuation,Ray& scattered) const override;

};

class Metal : public Material{
    public:
    Vec3 albedo;
    float fuzz;
    Metal(const Vec3& color,float f)
        :albedo(color) ,fuzz(f<1.0f ? f:1.0f){}
    virtual bool scatter(const Ray& r, const hit_record& rec,Vec3& attenuation,Ray& scattered) const override;
};