#include<iostream>
#include "Ler_arquivo.h"

Ler_arquivo::Ler_arquivo()
{
    //ctor
}

Ler_arquivo::~Ler_arquivo()
{
    //dtor
}

std::vector<FiguraGeometrica*> Ler_arquivo::parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s,token;

    if(!fin.is_open()){
        std::cout << "Arquivo não foi aberto: " << filename << std::endl;
    }

    while(fin.good()){
        std::getline(fin,s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if(token.compare("dim")==0){
                    ss >> dimx >> dimy >> dimz;
                }
                else if(token.compare("putvoxel")==0){
                    int x0,y0,z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back  (new PutVoxel(x0,y0,z0,r,g,b,a));
                }
                else if(token){
                   int x0,y0,z0,rr;
                   ss >> x0 >> y0 >> z0 >> rr >> r >> g >> b >> a;
                   figs.push_back  (new PutSphere(x0,y0,z0,rr,r,g,b,a));
                }
            }
        }
    }
    return(figs);
}

int Ler_arquivo>>getDimx(){
return dimx;
}
