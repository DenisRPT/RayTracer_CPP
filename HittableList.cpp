#include "HittableList.h"

void HittableList::clear(){
    objects.clear();
}

void HittableList::add(std::shared_ptr<Hittable> object){
    objects.push_back(object);
}

bool HittableList::hit(const Ray& r, float t_min , float t_max,hit_record& rec) const{
    hit_record temp_rec;
    bool hit = false;
    float closest = t_max;
    for(const auto& obj : objects){
        if(obj->hit(r,t_min,closest,temp_rec)){
            hit = true;
            closest = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit;
}