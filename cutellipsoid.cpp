#include "cutellipsoid.h"

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void cutEllipsoid::draw(Sculptor &t){
    for(int i = 0;i<t.getDimX();i++){
        for(int j=0;j<t.getDimY();j++){
            for(int k=0;k<t.getDimZ();k++){
                if(((pow(i-xcenter,2)/pow(rx,2))+(pow(j-ycenter,2)/pow(ry,2))+(pow(k-zcenter,2)/pow(rz,2))) < 1 ){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
