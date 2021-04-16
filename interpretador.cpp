#include "interpretador.h"

Interpretador::Interpretador()
{

}

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}

vector <FiguraGeometrica*> Interpretador::expor(string filename){
    int cont = 0;
    vector <FiguraGeometrica*> figs;
    ifstream fileIn;
    stringstream ss;
    string s, token;

    fileIn.open(filename);

    if(!fileIn.is_open()){
        cout<<"\"" <<filename <<"\" "<< "- Nao foi encontrado!"<<endl;
        exit(0);
    }

    while(getline(fileIn, s)){
        cont++;
        ss.clear();
        ss.str(s);
        ss>>token;
        if(token.compare("dim") == 0){
            ss >> dimx >> dimy >> dimz;
        }
        if(token.compare("putvoxel") == 0){
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            if(r<=1 && r>=0 && g<=1 && g>=0 && b<=1 && b>=0 && a<=1 && a>=0){
                figs.push_back(new putVoxel(x0,y0,z0,r,g,b,a));
            }else{
                cout<<"valores de cores invalidos: a figura " <<token <<" linha "<< cont << " nao sera desenhada!" <<endl;
            }
        }
        if(token.compare("putbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            if(r<=1 && r>=0 && g<=1 && g>=0 && b<=1 && b>=0 && a<=1 && a>=0){
                figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }else{
                cout<<"valores de cores invalidos: a figura " <<token <<" linha "<< cont << " nao sera desenhada!" <<endl;
            }

        }
        if(token.compare("putsphere") == 0){
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
            if(r<=1 && r>=0 && g<=1 && g>=0 && b<=1 && b>=0 && a<=1 && a>=0){
                figs.push_back(new putSphere(x0,y0,z0,radius,r,g,b,a));
            }else{
                cout<<"valores de cores invalidos: a figura " <<token <<" linha "<< cont << " nao sera desenhada!" <<endl;
            }
        }
        if(token.compare("putellipsoid") == 0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            if(r<=1 && r>=0 && g<=1 && g>=0 && b<=1 && b>=0 && a<=1 && a>=0){
                figs.push_back(new putEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
            }else{
                cout<<"valores de cores invalidos: a figura " <<token <<" linha "<< cont << " nao sera desenhada!" <<endl;
            }
        }
        if(token.compare("cutvoxel") == 0){
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0;
            figs.push_back(new cutVoxel(x0,y0,z0));
        }
        if(token.compare("cutbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }
        if(token.compare("cutsphere") == 0){
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius;
            figs.push_back(new cutSphere(x0,y0,z0,radius));
        }
        if(token.compare("cutellipsoid") == 0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(x0,y0,z0,rx,ry,rz));
        }
    }

    fileIn.close();

    return figs;
 }
