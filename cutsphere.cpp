#include "cutsphere.h"

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->x = xcenter;
    this->y = ycenter;
    this->z = zcenter;
    this->radius = radius;
}

void cutSphere::draw(Sculptor &t){
    for(int i = 0;i<t.getDimX();i++){
        for(int j=0;j<t.getDimY();j++){
            for(int k=0;k<t.getDimZ();k++){
                if((pow(i-x,2)+pow(j-y,2)+pow(k-z,2)) < pow(radius,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
