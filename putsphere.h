#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class putSphere : public FiguraGeometrica{
    int x, y, z, radius;
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
