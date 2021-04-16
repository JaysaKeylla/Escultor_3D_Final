#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class cutBox : public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;
public:
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
