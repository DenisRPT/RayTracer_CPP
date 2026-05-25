#pragma once
#include <cmath>

class Vec3{
    public:
    float x,y,z;
    Vec3() : x(0),y(0),z(0){}
    Vec3(float x,float y,float z) : 
        x(x),y(y),z(z) {}
    float operator[](int i) const;
    float& operator[](int i);
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(float s) const;
    Vec3 operator/(float s) const;
    float length() const;
    float length_squared() const;
};
