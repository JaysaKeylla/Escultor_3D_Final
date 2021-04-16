#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include"sculptor.h"

class PutVoxel : public FiguraGeometrica
{
    int x,y,z;
public:
        void putVoxel(int x, int y, int z,float r, float g, float b, float a);
        ~PutVoxel(){}
        void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
