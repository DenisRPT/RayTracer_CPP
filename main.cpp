#include <iostream>
#include <fstream>
#include <cmath>
#include "HittableList.h"
#include "Materials.h"
#include "Sphere.h"
#include "Quad.h"
#include "Box.h"


int main(){
    float RATIO = 16.0f/9.0f;
    int IMG_WIDTH = 400;
    int IMG_HEIGHT = static_cast<int>(IMG_WIDTH/RATIO);
    float VP_HEIGHT = 2.0f;
    float VP_WIDTH = RATIO*VP_HEIGHT;
    float FOCAL_LENGTH = 1.0f;
    int MAX_DEPTH = 10;

    auto mat_ground = std::make_shared<Lambertian>(Vec3(0.5f,0.5f,0.5f));
    auto mat_sphere = std::make_shared<Lambertian>(Vec3(0.1f,0.3f,0.8f));
    auto mat_box = std::make_shared<Lambertian>(Vec3(0.8f,0.2f,0.2f));
    auto mat_metal = std::make_shared<Metal>(Vec3(0.8f,0.8f,0.8f),0.1f);

    HittableList world;
    world.add(std::make_shared<Quad>(
        Vec3(-5.0f, -0.5f, -8.0f),
        Vec3(10.0f, 0.0f,  0.0f),
        Vec3(0.0f,  0.0f,  8.0f),
        mat_ground));
    world.add(std::make_shared<Sphere>(
        Vec3(-1.0f, 0.0f, -2.0f), 0.5f, mat_sphere));
    world.add(std::make_shared<Sphere>(
        Vec3(1.0f, 0.0f, -2.0f), 0.5f, mat_metal));
    world.add(std::make_shared<Box>(
        Vec3(-0.3f, -0.5f, -3.0f),
        Vec3(0.3f,   0.1f, -2.4f),
        mat_box));

    Vec3 origin;
    Vec3 horizontal(VP_WIDTH,0.0f,0.0f);
    Vec3 vertical(0.0f,VP_HEIGHT,0.0f);
    Vec3 ll_corner = origin-horizontal/2-vertical/2-Vec3(0.0f,0.0f,FOCAL_LENGTH);

    int samples_per_pixel = 100;

    std::ofstream out("rayImage.ppm");
    out << "P3\n" << IMG_WIDTH << ' ' << IMG_HEIGHT << "\n255\n";
    for(int j=IMG_HEIGHT-1;j>=0;--j){
        std::cerr<< "\rRendering row: " << j << ' ' << std::flush;
        for(int i=0;i<IMG_WIDTH;++i){
            Vec3 pixel_color;
            for(int s=0;s<samples_per_pixel;++s){
                float u =(float(i) + random_float())/(IMG_WIDTH-1);
                float v = (float(j) + random_float())/(IMG_HEIGHT-1);
                Vec3 direction = ll_corner+horizontal*u+vertical*v-origin;
                Ray r(origin,direction);
                pixel_color = pixel_color + ray_color(r,world,MAX_DEPTH);
            }
            float scale = 1.0f/samples_per_pixel;
            pixel_color = pixel_color*scale;
            pixel_color = Vec3(std::sqrt(pixel_color.x),
                               std::sqrt(pixel_color.y),
                               std::sqrt(pixel_color.z));

            int ir = static_cast<int>(255.999*pixel_color.x);
            int ig = static_cast<int>(255.999*pixel_color.y);
            int ib = static_cast<int>(255.999*pixel_color.z);

            if (ir > 255) ir = 255; if (ir < 0) ir = 0;
            if (ig > 255) ig = 255; if (ig < 0) ig = 0;
            if (ib > 255) ib = 255; if (ib < 0) ib = 0;
            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    out.close();
    std::cerr << "\nFinish.\n";
    return 0;
}