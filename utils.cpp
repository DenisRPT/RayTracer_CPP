#include "utils.h"

Vec3 ray_color(const Ray& r,const Hittable& world){
    hit_record rec;
    if(world.hit(r,0.001f,1000000.0f,rec)){
        return 0.5f*Vec3(rec.normal.x+1.0f,rec.normal.y+1.0f,rec.normal.z+1.0f);
    }
    
    Vec3 unit_direction = unit_vector(r.direction());
    float a = 0.5f*(unit_direction.y + 1.0f);
    return Vec3(1.0f,1.0f,1.0f)*(1.0f-a) + Vec3(0.5f,0.7f,1.0f)*a;
}
