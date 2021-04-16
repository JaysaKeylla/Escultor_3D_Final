#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include <iostream>
#include <math.h>
#include "sculptor.h"

using namespace std;

class FiguraGeometrica{

protected:
    float r, g, b, a;
public:
    virtual ~FiguraGeometrica(){};
    virtual void draw(Sculptor &t) = 0;
};

#endif // FIGURAGEOMETRICA_H
