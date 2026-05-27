#include "Vec3.h"

float Vec3::operator[](int i) const {
    if(i==0) return x;
    if(i==1) return y;
    return z;
}

float& Vec3::operator[](int i){
    if(i==0) return x;
    if(i==1) return y;
    return z;
}

Vec3 Vec3::operator+(const Vec3& v) const{
    return Vec3(x+v.x,y+v.y,z+v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const{
    return Vec3(x-v.x,y-v.y,z-v.z);
}

Vec3 Vec3::operator*(float s) const{
    return Vec3(x*s,y*s,z*s);
}

Vec3 Vec3::operator/(float s) const{
    return Vec3(x/s,y/s,z/s);
}

float Vec3::length() const{
    return std::sqrt(x*x+y*y+z*z);
}

float Vec3::length_squared() const{
    return (x*x+y*y+z*z);
}

