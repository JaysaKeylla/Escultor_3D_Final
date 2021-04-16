#include <iostream>
#include "figurageometrica.h"
#include "interpretador.h"
#include <vector>

using namespace std;

int main()
{
    Sculptor *s1;

    vector<FiguraGeometrica*> figs;
    Interpretador dados;
    figs = dados.expor("Teste.txt");

    s1 = new Sculptor(dados.getDimx(),dados.getDimy(),dados.getDimz());

    for(size_t i=0; i<figs.size(); i++){
        cout<<"Draw"<<endl;
        figs[i]->draw(*s1);
    }

    s1->writeOFF((char*)"teste.off");

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }

    delete s1;

    cout << "fim!";
    return 0;
}
