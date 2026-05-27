#include "Material.h"
#include "utils.h"

Vec3 ray_color(const Ray& r,const Hittable& world,int depth){
    if(depth<=0 ){
        return Vec3();
    }
    hit_record rec;
        if(world.hit(r, 0.001f, 10000.0f, rec)){
        Ray scattered;
        Vec3 attenuation;
        if(rec.material && rec.material->scatter(r, rec, attenuation, scattered)){
            Vec3 bounced = ray_color(scattered, world, depth - 1);
            return Vec3(attenuation.x * bounced.x,
                        attenuation.y * bounced.y,
                        attenuation.z * bounced.z);
        }
        return Vec3(0.0f, 0.0f, 0.0f);
    }

    Vec3 unit_direction = unit_vector(r.direction());
    float a = 0.5f*(unit_direction.y + 1.0f);
    return Vec3(1.0f,1.0f,1.0f)*(1.0f-a) + Vec3(0.5f,0.7f,1.0f)*a;
}