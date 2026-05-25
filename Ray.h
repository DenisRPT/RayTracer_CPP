#pragma once
#include "Vec3.h"

class Ray{
    private:
    Vec3 orig;
    Vec3 dir;
    public:
    Ray(){}
    Ray(const Vec3& origin,const Vec3& direction):
        orig(origin),dir(direction){}
    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 at(float t) const;
};