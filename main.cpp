#include <iostream>
#include<cstring>
#include "sculptor.h"

using namespace std;

int main(void)
{
    Sculptor *s1;
    Sculptor s(30,20,30)
    Sculptor nintendo(30, 10, 50);

    Ler_arquivo parser;
    std::vector<FiguraGeometrica*> figs;

    figs = parser.parse("Escultura.txt");

    for(size_t i=0; i<figs.size(); i++){
        cout << "Draw" << endl;
        figs[i]->draw(*s1);
    }

    s1-> limpavoxels();

    for (size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }
    delete s1;

    return 0;
}
