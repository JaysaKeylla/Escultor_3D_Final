#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica
{
    int x, y, z, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
