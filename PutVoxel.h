#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include"sculptor.h"

class PutVoxel : public FiguraGeometrica
{
    int x,y,z;
public:
        void putVoxel(int x, int y, int z);
        ~PutVoxel(){}
        void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
