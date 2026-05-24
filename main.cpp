#include <iostream>
#include <fstream>
#include <cmath>
#include "Vec3.h"

#define WIDTH 256
#define HEIGHT 256

int main(){
    std::ofstream out("rayImage.ppm");
    out << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
    for(int j=HEIGHT-1;j>=0;--j){
        std::cerr<< "\rRendering row: " << j << ' ' << std::flush;
        for(int i=0;i<WIDTH;++i){
            float r = float(i) /(WIDTH-1);
            float g =float(j)/(HEIGHT-1);
            float b = 0.25f;
            Vec3 pixel_color(r,g,b);
            int ir = static_cast<int>(255.999*pixel_color.x);
            int ig = static_cast<int>(255.999*pixel_color.y);
            int ib = static_cast<int>(255.999*pixel_color.z);
            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    out.close();
    std::cerr << "\nFinish.\n";
    return 0;
}