#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class cutEllipsoid : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
