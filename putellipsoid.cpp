#include "putellipsoid.h"

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void putEllipsoid::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = 0;i<t.getDimX();i++){
        for(int j=0;j<t.getDimY();j++){
            for(int k=0;k<t.getDimZ();k++){
                if(((pow(i-xcenter,2)/pow(rx,2))+(pow(j-ycenter,2)/pow(ry,2))+(pow(k-zcenter,2)/pow(rz,2))) < 1 ){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
