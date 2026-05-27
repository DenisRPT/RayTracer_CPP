#pragma once
#include "Vec3.h"
#include "Ray.h"

struct hit_record;

class Material{
public:
virtual ~Material() = default;
virtual bool scatter(const Ray&r,const hit_record& rec,Vec3& attenuation,Ray& scattered) const = 0;
};