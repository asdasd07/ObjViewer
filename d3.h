#ifndef D3_H
#define D3_H

#include <QWidget>

class d3 : public QWidget
{
    Q_OBJECT
public:
    explicit d3(QWidget *parent = NULL);
protected:
    void paintEvent(QPaintEvent *event);
public:
    struct Vertex{
        float x=0,y=0,z=0, primx=0, primy=0, primz=0;
        Vertex(){
        }
        Vertex(float xx,float yy){
            x=xx; y=yy;
        }
        Vertex(float xx,float yy,float zz){
            primx=xx; primy=yy; primz=zz;
        }
    };
    struct uvTriangle{
        float x=0,y=0,u=0,v=0,nx=0,ny=0,nz=0;
        uvTriangle(){
        }
        uvTriangle(float xx,float yy){
            x=xx; y=yy;
        }
        uvTriangle(float xx,float yy,float uu,float vv){
            x=xx; y=yy; u=uu; v=vv;
        }
        uvTriangle(float xx,float yy,float uu,float vv,float xn,float yn,float zn){
            x=xx; y=yy; u=uu; v=vv; nx=xn; ny=yn; nz=zn;
        }
    };
    struct Face{
        int a=0,b=0,c=0;
        Face(){}
        Face(int aa,int bb,int cc){
            a=aa;b=bb;c=cc;
        }
    };
    struct Kolor{
        int r=0,g=0,b=0;
        Kolor(){}
        Kolor(int rr,int gg,int bb){
            r=std::min(rr, 255);
            g=std::min(gg, 255);
            b=std::min(bb, 255);
            r=std::max(r, 0);
            g=std::max(g, 0);
            b=std::max(b, 0);
        }
    };
private:
    int vvsize=0,vnsize=0,vtsize=0,fsize=0;
    Vertex *vv=nullptr, *vn=nullptr, *vt=nullptr;
    Face *ff=nullptr, *fn=nullptr, *ft=nullptr;
    QImage canvas, Tex, norm;
    bool wireframing=true, backfacing=false, texturing=false, ortografik=true, painter=false, phong=false, filling=false, nmap=false;
    float posx=0,posy=0,posz=5;
    float rotx=0,roty=0,rotz=0,sizx=1,sizy=1,sizz=1,fov=500,cx=0,cy=0, Lh=0, Lw=0,kk1=1,kk2=1,kk3=1;
    int kk4=20;
    Vertex center, L=Vertex(1,0,0), V=Vertex(0,0,-1);
    void parseObjFile(const QString fileName);
    void transform();
    void drawAll();
    bool isBackface(int i);
    void Normalize(Vertex *v);
    void Line3(int x,int y,int x2, int y2);
    void putPixel(int x,int y, Kolor *k);
    Kolor getPixel(QImage *img, float x,float y);
    void Textur(int i);
    void drawHorizontal(float *Xl, float *Xr, float *Y, float *Ul, float *Vl, float *Ur, float *Vr);
    void drawHorizontal(float *Xl, float *Xr, float *Y, float *Ul, float *Vl, float *Ur, float *Vr, Vertex *Nd, Vertex *Nf);

public slots:
    void load();
    void posX(double n);
    void posY(double n);
    void posZ(double n);
    void fo(int n);
    void rotX(double n);
    void rotY(double n);
    void rotZ(double n);
    void sizX(double n);
    void sizY(double n);
    void sizZ(double n);
    void OoP(bool);
    void wireframe(bool n);
    void back(bool n);
    void tex(bool n);
    void mal(bool n);
    void pho(bool n);
    void fac(bool n);
    void nm(bool n);
    void ligH(int n);
    void ligW(int n);
    void k1(double n);
    void k2(double n);
    void k3(double n);
    void k4(int n);
};

#endif // D3_H
