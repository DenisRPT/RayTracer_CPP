#include "Ray.h"

Vec3 Ray::origin() const{
    return orig;
}

Vec3 Ray::direction() const{
    return dir;
}

Vec3 Ray::at(float t) const{
    //P(t) = A + tB , A-origin B-direcion t-time period
    return orig+dir*t;
}