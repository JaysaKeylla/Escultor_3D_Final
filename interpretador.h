#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "figurageometrica.h"
#include "sculptor.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"

class Interpretador
{
protected:
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    int getDimx();
    int getDimy();
    int getDimz();
    vector <FiguraGeometrica*> expor(string filename);
};

#endif // INTERPRETADOR_H
