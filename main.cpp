#include <iostream>
#include <fstream>
#include <cmath>
#include "utils.h"


int main(){
    float RATIO = 16.0f/9.0f;
    int IMG_WIDTH = 400;
    int IMG_HEIGHT = static_cast<int>(IMG_WIDTH/RATIO);
    float VP_HEIGHT = 2.0f;
    float VP_WIDTH = RATIO*VP_HEIGHT;
    float FOCAL_LENGTH = 1.0f;
    
    Vec3 origin;
    Vec3 horizontal(VP_WIDTH,0.0f,0.0f);
    Vec3 vertical(0.0f,VP_HEIGHT,0.0f);
    Vec3 ll_corner = origin-horizontal/2-vertical/2-Vec3(0.0f,0.0f,FOCAL_LENGTH);

    std::ofstream out("rayImage.ppm");
    out << "P3\n" << IMG_WIDTH << ' ' << IMG_HEIGHT << "\n255\n";
    for(int j=IMG_HEIGHT-1;j>=0;--j){
        std::cerr<< "\rRendering row: " << j << ' ' << std::flush;
        for(int i=0;i<IMG_WIDTH;++i){
            float u = float(i)/(IMG_WIDTH-1);
            float v = float(j)/(IMG_HEIGHT-1);
            Vec3 direction = ll_corner+horizontal*u+vertical*v-origin;
            Ray r(origin,direction);
            Vec3 pixel_color = ray_color(r);
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