#include "putsphere.h"

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    this->x = xcenter;
    this->y = ycenter;
    this->z = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void putSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = 0;i<t.getDimX();i++){
        for(int j=0;j<t.getDimY();j++){
            for(int k=0;k<t.getDimZ();k++){
                if((pow(i-x,2)+pow(j-y,2)+pow(k-z,2)) < pow(radius,2)){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
