#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H


class FiguraGeometrica
{
    public:
        FiguraGeometrica();
        virtual ~FiguraGeometrica(){}
        virtual void draw()=0;   //metodo virtual puro

};

#endif // FIGURAGEOMETRICA_H
