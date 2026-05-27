#include "Box.h"

Box::Box(const Vec3&a ,const Vec3&b , std::shared_ptr<Material> mat){
    float dx = b.x-a.x;
    float dy = b.y-a.y;
    float dz = b.z-a.z;
    Vec3 right (dx, 0.0f, 0.0f);
    Vec3 up (0.0f, dy ,0.0f);
    Vec3 forward (0.0f ,0.0f,dz);

    sides.add(std::make_shared<Quad>(
        Vec3(a.x, a.y, b.z), right, up, mat));
    sides.add(std::make_shared<Quad>(
        Vec3(b.x, a.y, a.z), Vec3(-dx, 0.0f, 0.0f), up, mat));
    sides.add(std::make_shared<Quad>(
        Vec3(a.x, a.y, a.z), forward, up, mat));
    sides.add(std::make_shared<Quad>(
        Vec3(b.x, a.y, b.z), Vec3(0.0f, 0.0f, -dz), up, mat));
    sides.add(std::make_shared<Quad>(
        Vec3(a.x, a.y, a.z), right, forward, mat));
    sides.add(std::make_shared<Quad>(
        Vec3(a.x, b.y, b.z), right, Vec3(0.0f, 0.0f, -dz), mat));
}

bool Box::hit(const Ray&r ,float t_min,float t_max,hit_record& rec) const{
    return sides.hit(r,t_min,t_max,rec);
}