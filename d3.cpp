#include "d3.h"
#include <QDir>
#include <QFileDialog>
#include <QImageReader>
#include <QPainter>
#include <math.h>

//load defaut obj
d3::d3(QWidget *parent) : QWidget(parent){
    canvas = QImage(900,600,QImage::Format_RGB32);
    canvas.fill(Qt::black);
    cx=canvas.width()/2;
    cy=canvas.height()/2;

    QString dr=QDir::currentPath();
    parseObjFile(dr+"\\Sphere.obj");
    Tex = QImage(dr+"\\Basketball_BaseColor.jpg");
    norm = QImage(dr+"\\Metal_Normal.jpg");
    transform();
}

//load obj, texture, normal map from dailog window 
void d3::load(){
    QString wybor;
    wybor = QFileDialog::getOpenFileName(this,"Wybierz model",QDir::currentPath(),"*.obj");
    if(wybor.isNull()==false){
        delete vv;
        delete vn;
        delete vt;
        delete ff;
        delete fn;
        delete ft;
        parseObjFile(wybor);
    }
    else{
        return;
    }
    wybor = QFileDialog::getOpenFileName(this,"Wybierz teksture",QDir::currentPath(),"*.png *.jpg");
    if(wybor.isNull()){
        Tex=QImage(1,1,QImage::Format_RGB32);
    }
    else{
        Tex=QImage(wybor);
    }
    wybor = QFileDialog::getOpenFileName(this,"Wybierz normal map",QDir::currentPath(),"*.png *.jpg");
    if(wybor.isNull()){
        norm=QImage(1,1,QImage::Format_RGB32);
    }
    else{
        norm=QImage(wybor);
    }

    qDebug("%d", fsize);
    qDebug("%d, %d, %d", vvsize, vnsize, vtsize);

    float minx=vv[0].primx,maxx=vv[0].primx;
    float miny=vv[0].primy,maxy=vv[0].primy;
    float minz=vv[0].primz,maxz=vv[0].primz;

    for(int i=0; i<vvsize;i++){
        minx= minx<vv[i].primx ?vv[i].primx :minx;
        maxx= maxx>vv[i].primx ?vv[i].primx :maxx;
        miny= miny<vv[i].primy ?vv[i].primy :miny;
        maxy= maxy>vv[i].primy ?vv[i].primy :maxy;
        minz= minz<vv[i].primz ?vv[i].primz :minz;
        maxz= maxz>vv[i].primz ?vv[i].primz :maxz;
    }
    center.x=(minx+maxx)/2;
    center.y=(miny+maxy)/2;
    center.z=(minz+maxz)/2;
    transform();
}

void d3::transform(){
	//transform size,rotation,position of object without matrix
    for(int i=0; i<vvsize; i++){
        vv[i].x=vv[i].primx*sizx;
        vv[i].y=vv[i].primy*sizy;
        vv[i].z=vv[i].primz*sizz;

        Vertex copy=vv[i];
        vv[i].y=(float)(copy.y*cos(rotx))-(float)(copy.z*sin(rotx));
        vv[i].z=(float)(copy.y*sin(rotx))+(float)(copy.z*cos(rotx));
        copy=vv[i];
        vv[i].x=(float)(copy.x*cos(roty))+(float)(copy.z*sin(roty));
        vv[i].z=(float)(-copy.x*sin(roty))+(float)(copy.z*cos(roty));
        copy=vv[i];
        vv[i].x=(float)(copy.x*cos(rotz))-(float)(copy.y*sin(rotz));
        vv[i].y=(float)(copy.x*sin(rotz))+(float)(copy.y*cos(rotz));

        vv[i].x+=posx;
        vv[i].y+=posy;
        vv[i].z+=posz;
		//ortografik or perspective
        if(ortografik){
            vv[i].x=vv[i].x/(posz/fov)+cx;
            vv[i].y=vv[i].y/(posz/fov)+cy;
        }
        else{
            Vertex copy=vv[i];
            copy.z= copy.z==0 ? 0.1 :copy.z;
            vv[i].x=fov*(float)(copy.x/copy.z)+cx;
            vv[i].y=fov*(float)(copy.y/copy.z)+cy;
        }
    }
	//transform ratation of normal vectors
    for(int i=0; i<vnsize; i++ ){
        Vertex copy=vn[i];
        vn[i].y=(float)(copy.primy*cos(rotx))-(float)(copy.primz*sin(rotx));
        vn[i].z=(float)(copy.primy*sin(rotx))+(float)(copy.primz*cos(rotx));
        copy=vn[i];
        vn[i].x=(float)(copy.primx*cos(roty))+(float)(copy.z*sin(roty));
        vn[i].z=(float)(-copy.primx*sin(roty))+(float)(copy.z*cos(roty));
        copy=vn[i];
        vn[i].x=(float)(copy.x*cos(rotz))-(float)(copy.y*sin(rotz));
        vn[i].y=(float)(copy.x*sin(rotz))+(float)(copy.y*cos(rotz));
    }
    drawAll();
}

void d3::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawImage(0,0,canvas);
}

void d3::drawAll(){
    canvas.fill(Qt::black);
    std::vector< std::pair <float,int> > vect;
    for(int i=0; i<fsize; i++){
		//if backface cooling on and in fornt of camera
        //or backface cooling off and painter's algorithm off
        if((backfacing && isBackface(i)) || (!backfacing && !painter)){
            if(painter){
//                float min1 = (vv[ff[i].a].z+vv[ff[i].b].z+vv[ff[i].c].z)/3;
                float min1=vv[ff[i].a].z < vv[ff[i].b].z ? vv[ff[i].a].z : vv[ff[i].b].z;
                min1=vv[ff[i].c].z < min1 ? vv[ff[i].c].z : min1;
                vect.push_back(std::make_pair(min1,i));
            }
            else{
                if(filling){
                    Textur(i);
                }
                if(wireframing){
                    Line3(vv[ff[i].a].x, vv[ff[i].a].y, vv[ff[i].b].x, vv[ff[i].b].y);
                    Line3(vv[ff[i].b].x, vv[ff[i].b].y, vv[ff[i].c].x, vv[ff[i].c].y);
                    Line3(vv[ff[i].c].x, vv[ff[i].c].y, vv[ff[i].a].x, vv[ff[i].a].y);
                }
            }
        }
        if(!backfacing && painter){
            //float min1 = (vv[ff[i].a].z+vv[ff[i].b].z+vv[ff[i].c].z)/3;
            float min1=vv[ff[i].a].z < vv[ff[i].b].z ? vv[ff[i].a].z : vv[ff[i].b].z;
            min1=vv[ff[i].c].z < min1 ? vv[ff[i].c].z : min1;
            vect.push_back(std::make_pair(min1,i));
        }
    }
    if(painter){
        sort(vect.begin(), vect.end());
        for(int i=vect.size()-1; i>=0; i--){

            if(filling){
                Textur(vect[i].second);
            }

            if(wireframing){
                Line3(vv[ff[vect[i].second].a].x, vv[ff[vect[i].second].a].y, vv[ff[vect[i].second].b].x, vv[ff[vect[i].second].b].y);
                Line3(vv[ff[vect[i].second].b].x, vv[ff[vect[i].second].b].y, vv[ff[vect[i].second].c].x, vv[ff[vect[i].second].c].y);
                Line3(vv[ff[vect[i].second].c].x, vv[ff[vect[i].second].c].y, vv[ff[vect[i].second].a].x, vv[ff[vect[i].second].a].y);
            }
        }
    }
    update();
}
//is in front of the camera
bool d3::isBackface(int i){
    Vertex va,vb;
    va.x= vv[ff[i].b].x - vv[ff[i].a].x;
    va.y= vv[ff[i].b].y - vv[ff[i].a].y;
    va.z= vv[ff[i].b].z - vv[ff[i].a].z;
    vb.x= vv[ff[i].c].x - vv[ff[i].a].x;
    vb.y= vv[ff[i].c].y - vv[ff[i].a].y;
    vb.z= vv[ff[i].c].z - vv[ff[i].a].z;
    Vertex n(va.y*vb.z - va.z*vb.y, va.z*vb.x - va.x*vb.z, va.x*vb.y - va.y*vb.x);
    Normalize(&n);
    float tt= vv[ff[i].a].x * n.primx + vv[ff[i].a].y * n.primy + (vv[ff[i].a].z-500.0) * n.primz ;
    if(tt>=0){
        return true;
    }
  return false;
}
void d3::Normalize(Vertex *v){
    float q=sqrt((v->primx*v->primx)+(v->primy*v->primy)+(v->primz*v->primz));
    v->primx/= q;
    v->primy/= q;
    v->primz/= q;
}
void d3::Textur(int i){
    uvTriangle t[3];

    int wid=std::min(Tex.width(),Tex.height());
    //no normal vertex
    if(vnsize==0){
        //no textur vetex
        if(vtsize==0){
            t[0]=uvTriangle(vv[ff[i].a].x, vv[ff[i].a].y, 0,0);
            t[1]=uvTriangle(vv[ff[i].b].x, vv[ff[i].b].y, 0,0);
            t[2]=uvTriangle(vv[ff[i].c].x, vv[ff[i].c].y, 0,0);
        }
        else{
            t[0]=uvTriangle(vv[ff[i].a].x, vv[ff[i].a].y, vt[ft[i].a].x * wid, vt[ft[i].a].y * wid);
            t[1]=uvTriangle(vv[ff[i].b].x, vv[ff[i].b].y, vt[ft[i].b].x * wid, vt[ft[i].b].y * wid);
            t[2]=uvTriangle(vv[ff[i].c].x, vv[ff[i].c].y, vt[ft[i].c].x * wid, vt[ft[i].c].y * wid);
        }
    }

    else{
        //no textur vetex
        if(vtsize==0){
            t[0]=uvTriangle(vv[ff[i].a].x, vv[ff[i].a].y, 0,0, vn[fn[i].a].x, vn[fn[i].a].y, vn[fn[i].a].z);
            t[1]=uvTriangle(vv[ff[i].b].x, vv[ff[i].b].y, 0,0, vn[fn[i].b].x, vn[fn[i].b].y, vn[fn[i].b].z);
            t[2]=uvTriangle(vv[ff[i].c].x, vv[ff[i].c].y, 0,0, vn[fn[i].c].x, vn[fn[i].c].y, vn[fn[i].c].z);
        }
        else{
            t[0]=uvTriangle(vv[ff[i].a].x, vv[ff[i].a].y, vt[ft[i].a].x * wid, vt[ft[i].a].y * wid, vn[fn[i].a].x, vn[fn[i].a].y, vn[fn[i].a].z);
            t[1]=uvTriangle(vv[ff[i].b].x, vv[ff[i].b].y, vt[ft[i].b].x * wid, vt[ft[i].b].y * wid, vn[fn[i].b].x, vn[fn[i].b].y, vn[fn[i].b].z);
            t[2]=uvTriangle(vv[ff[i].c].x, vv[ff[i].c].y, vt[ft[i].c].x * wid, vt[ft[i].c].y * wid, vn[fn[i].c].x, vn[fn[i].c].y, vn[fn[i].c].z);
        }
    }
    //sort by descending Y
    if(t[0].y>t[1].y){
        std::swap(t[0],t[1]);
    }
    if(t[1].y>t[2].y){
        std::swap(t[1],t[2]);
    }
    if(t[0].y>t[1].y){
        std::swap(t[0],t[1]);
    }
    //interpolation t0-t1
    for(float y=t[0].y; y<=t[1].y; y++){
        float alfaL=(y-t[0].y)/(t[1].y-t[0].y);
                float Xl=t[0].x+alfaL*(t[1].x-t[0].x);
                float Ul=t[0].u+alfaL*(t[1].u-t[0].u);
                float Vl=t[0].v+alfaL*(t[1].v-t[0].v);

        float alfaR=(y-t[0].y)/(t[2].y-t[0].y);
                float Xr=t[0].x+alfaR*(t[2].x-t[0].x);
                float Ur=t[0].u+alfaR*(t[2].u-t[0].u);
                float Vr=t[0].v+alfaR*(t[2].v-t[0].v);

        if(!phong){
            drawHorizontal(&Xl, &Xr, &y, &Ul, &Vl, &Ur, &Vr);
        }
        else{
            Vertex Nd(t[2].nx*alfaR+t[0].nx*(1-alfaR), t[2].ny*alfaR+t[0].ny*(1-alfaR), t[2].nz*alfaR+t[0].nz*(1-alfaR));
            Vertex Nf(t[1].nx*alfaL+t[0].nx*(1-alfaL), t[1].ny*alfaL+t[0].ny*(1-alfaL), t[1].nz*alfaL+t[0].nz*(1-alfaL));
            Normalize(&Nd);
            Normalize(&Nf);
            drawHorizontal(&Xl, &Xr, &y, &Ul, &Vl, &Ur, &Vr, &Nf, &Nd);
        }
    }
    //interpolation t1-t2
    for(float y=t[1].y; y<=t[2].y; y++){
        float alfaL=(y-t[1].y)/(t[2].y-t[1].y);
                float Xl=t[1].x+alfaL*(t[2].x-t[1].x);
                float Ul=t[1].u+alfaL*(t[2].u-t[1].u);
                float Vl=t[1].v+alfaL*(t[2].v-t[1].v);

        float alfaR=(y-t[0].y)/(t[2].y-t[0].y);
                float Xr=t[0].x+alfaR*(t[2].x-t[0].x);
                float Ur=t[0].u+alfaR*(t[2].u-t[0].u);
                float Vr=t[0].v+alfaR*(t[2].v-t[0].v);

        if(!phong){
            drawHorizontal(&Xl, &Xr, &y, &Ul, &Vl, &Ur, &Vr);
        }
        else{
            Vertex Nd(t[2].nx*alfaR+t[0].nx*(1-alfaR), t[2].ny*alfaR+t[0].ny*(1-alfaR), t[2].nz*alfaR+t[0].nz*(1-alfaR));
            Vertex Nf(t[2].nx*alfaL+t[1].nx*(1-alfaL), t[2].ny*alfaL+t[1].ny*(1-alfaL), t[2].nz*alfaL+t[1].nz*(1-alfaL));
            Normalize(&Nd);
            Normalize(&Nf);
            drawHorizontal(&Xl, &Xr, &y, &Ul, &Vl, &Ur, &Vr, &Nf, &Nd);
        }
    }
}

void d3::drawHorizontal(float *Xl, float *Xr, float *Y, float *Ul, float *Vl, float *Ur, float *Vr){
    if(*Xl>*Xr){
        std::swap(Xl,Xr);
        std::swap(Ul,Ur);
        std::swap(Vl,Vr);
    }
    for(float x=*Xl; x<*Xr; x++){
        float a=(x-*Xl)/(*Xr-*Xl);
        float u=*Ul+a*(*Ur-*Ul);
        float v=*Vl+a*(*Vr-*Vl);
        Kolor k;
        if(texturing && vtsize!=0){
            k=getPixel(&Tex, u, v);
        }
        else{
            k=Kolor(100,100,100);
        }
        putPixel(x, *Y, &k);
    }
}
void d3::drawHorizontal(float *Xl, float *Xr, float *Y, float *Ul, float *Vl, float *Ur, float *Vr, Vertex *Nf, Vertex *Nd){
    if(*Xl>*Xr){
        std::swap(Xl,Xr);
        std::swap(Nd,Nf);
        std::swap(Ul,Ur);
        std::swap(Vl,Vr);
    }
    for(float x=*Xl; x<*Xr; x++){
        float a=(float)(x-*Xl)/(*Xr-*Xl);
        float u=*Ul+a*(*Ur-*Ul);
        float v=*Vl+a*(*Vr-*Vl);
        //normal maping
        Vertex Ne(Nf->primx*(1-a)+Nd->primx*a, Nf->primy*(1-a)+Nd->primy*a, Nf->primz*(1-a)+Nd->primz*a);
        Normalize(&Ne);
        if(nmap){
            Kolor kn=getPixel(&norm, u, v);
            Vertex col(kn.r/255.0*2-1, kn.g/255.0*2-1, kn.b/255.0*2-1);
            Ne.primx+=col.primx;
            Ne.primy+=col.primy;
            Ne.primz-=col.primz;
            Normalize(&Ne);
        }
        //light intensivity
        float I=L.primx*Ne.primx+L.primy*Ne.primy+L.primz*Ne.primz;
        Vertex R(2*I*Ne.primx-L.primx, 2*I*Ne.primy-L.primy, 2*I*Ne.primz-L.primz);
        Normalize(&R);
        float Ir=R.primx*V.primx+R.primy*V.primy+R.primz*V.primz;
        Ir= Ir<0 ?0 :Ir;
        Ir=pow(Ir,kk4);
        I=kk1+I*kk2+kk3*Ir;
        //kolor calculation
        Kolor k;
        if(texturing && vtsize!=0){
            k=getPixel(&Tex, u, v);
        }
        else{
            k=Kolor(100,100,100);
        }
        k.r*=I;
        k.g*=I;
        k.b*=I;
        k.r=std::min(k.r, 255);
        k.g=std::min(k.g, 255);
        k.b=std::min(k.b, 255);
        k.r=std::max(k.r, 0);
        k.g=std::max(k.g, 0);
        k.b=std::max(k.b, 0);
        putPixel(x, *Y, &k);
    }
}
//put pixel on canvas
void d3::putPixel(int x, int y, Kolor *k){
    if(x>=0 && y>=0 && x<=canvas.width() && y<=canvas.height()){
        uchar *buff = canvas.scanLine(y);
        buff[4*x]=k->b;//blue
        buff[4*x+1]=k->g;//green
        buff[4*x+2]=k->r;//red
    }
}
//get Kolor from img
d3::Kolor d3::getPixel(QImage *img, float x, float y){
    Kolor a=Kolor(255,0,0);
    int u=x;
    int v=y;
    if(u<0 || v<0 || u>img->width() || v>img->height()){
        return a;
    }
    uchar *buff = img->scanLine(v);
    a.b= buff[4*u];
    a.g= buff[4*u+1];
    a.r= buff[4*u+2];
    return a;
}

//draw blue line
void d3::Line3(int x,int y,int x2, int y2) {
    Kolor k(0,0,255);
    int w = x2 - x ;
    int h = y2 - y ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
    if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
    if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;
    int longest = std::abs(w) ;
    int shortest = std::abs(h) ;
    if (!(longest>shortest)) {
        longest = std::abs(h) ;
        shortest = std::abs(w) ;
        if (h<0) dy2 = -1 ; else if (h>0) dy2 = 1 ;
        dx2 = 0 ;
    }
    int numerator = longest >> 1 ;
    for (int i=0;i<=longest;i++) {
        putPixel(x,y, &k) ;
        numerator += shortest ;
        if (!(numerator<longest)) {
            numerator -= longest ;
            x += dx1 ;
            y += dy1 ;
        } else {
            x += dx2 ;
            y += dy2 ;
        }
    }
}
//parse obj to arrays
void d3::parseObjFile(const QString fileName){
    QFile file(fileName);
    vvsize=0;vnsize=0;vtsize=0;fsize=0;
    //count vertexes and faces
    if (file.exists()){
        if (file.open(QFile::ReadOnly | QFile::Text)){
            while (!file.atEnd()){
                QString line = file.readLine().trimmed();
                QStringList lineParts = line.split(' ');
                if (lineParts.count() > 0)
                {
                    if (lineParts.at(0).compare("v", Qt::CaseInsensitive) == 0){
                        vvsize++;
                    }
                    else if (lineParts.at(0).compare("vn", Qt::CaseInsensitive) == 0){
                        vnsize++;
                    }
                    else if (lineParts.at(0).compare("vt", Qt::CaseInsensitive) == 0){
                        vtsize++;
                    }
                    else if (lineParts.at(0).compare("f", Qt::CaseInsensitive) == 0){
                        fsize++;
                    }
                }
            }
            vv= new Vertex [vvsize];
            vn= new Vertex [vnsize];
            vt= new Vertex [vtsize];
            ff= new Face[fsize];
            fn= new Face[fsize];
            ft= new Face[fsize];
        }
        file.close();

        if (file.open(QFile::ReadOnly | QFile::Text)){
            int vcount=0,vncount=0,vtcount=0,fcount=0,ftcount=0,fncount=0;
            while (!file.atEnd()){
                QString line = file.readLine().trimmed();
                QStringList lineParts = line.split(' ');
                if (lineParts.count() > 0)
                {
                    // if it’s a vertex position (v)
                    if (lineParts.at(0).compare("v", Qt::CaseInsensitive) == 0){
                        vv[vcount]=Vertex(lineParts.at(1).toFloat(), -lineParts.at(2).toFloat(), -lineParts.at(3).toFloat());
                        vcount++;
                    }
                    // if it’s a normal (vn)
                    else if (lineParts.at(0).compare("vn", Qt::CaseInsensitive) == 0){
                        float a=lineParts.at(1).toFloat();
                        float b=-lineParts.at(2).toFloat();
                        float c=-lineParts.at(3).toFloat();
                        vn[vncount]=(Vertex(a,b,c));
                        vncount++;
                    }
                    // if it’s a texture (vt)
                    else if (lineParts.at(0).compare("vt", Qt::CaseInsensitive) == 0){
                        float a=lineParts.at(1).toFloat();
                        float b=1.0-lineParts.at(2).toFloat();
                        vt[vtcount]=(Vertex(a,b));
                        vtcount++;
                    }
                    // if it’s face data (f)
                    // there’s an assumption here that faces are all triangles
                    else if (lineParts.at(0).compare("f", Qt::CaseInsensitive) == 0){
                        int a= lineParts.at(1).split("/").at(0).toInt();
                        int b= lineParts.at(2).split("/").at(0).toInt();
                        int c= lineParts.at(3).split("/").at(0).toInt();
                        ff[fcount]=(Face(a-1, b-1, c-1));
                        fcount++;
                        if (vtsize > 0) // check if really there are any UV coords
                        {
                            a= lineParts.at(1).split("/").at(1).toInt();
                            b= lineParts.at(2).split("/").at(1).toInt();
                            c= lineParts.at(3).split("/").at(1).toInt();
                            ft[ftcount]=(Face(a-1, b-1, c-1));
                            ftcount++;
                        }
                        if (vnsize > 0){
                            a= lineParts.at(1).split("/").at(2).toInt();
                            b= lineParts.at(2).split("/").at(2).toInt();
                            c= lineParts.at(3).split("/").at(2).toInt();
                            fn[fncount]=(Face(a-1, b-1, c-1));
                            fncount++;
                        }
                    }
                }
            }

            file.close();
        }
    }
}
void d3::posX(double n){
    posx=n;
    transform();
}
void d3::posY(double n){
    posy=n;
    transform();
}
void d3::posZ(double n){
    posz=n;
    transform();
}
void d3::rotX(double n){
    rotx=n;
    transform();
}
void d3::rotY(double n){
    roty=n;
    transform();
}
void d3::rotZ(double n){
    rotz=n;
    transform();
}
void d3::sizX(double n){
    sizx=n;
    transform();
}
void d3::sizY(double n){
    sizy=n;
    transform();
}
void d3::sizZ(double n){
    sizz=n;
    transform();
}
void d3::fo(int n){
    fov=n;
    transform();
}
void d3::OoP(bool n){
    ortografik=n;
    transform();
}
void d3::wireframe(bool n){
    wireframing=n;
    drawAll();
}
void d3::back(bool n){
    backfacing=n;
    drawAll();
}
void d3::tex(bool n){
    texturing=n;
    drawAll();
}
void d3::mal(bool n){
    painter=n;
    drawAll();
}
void d3::pho(bool n){
    phong=n;
    drawAll();
}
void d3::fac(bool n){
    filling=n;
    drawAll();
}
void d3::nm(bool n){
    nmap=n;
    drawAll();
}
void d3::ligH(int n){
    Lh= -n/180.0* M_PI;
    L=Vertex(cos(Lw)*cos(Lh), sin(Lh), sin(Lw)*cos(Lh));
    drawAll();
}
void d3::ligW(int n){
    Lw= n/180.0* M_PI;
    L=Vertex(cos(Lw)*cos(Lh), sin(Lh), sin(Lw)*cos(Lh));
    drawAll();
}
void d3::k1(double n){
    kk1=n;
    if(phong){
        drawAll();
    }
}
void d3::k2(double n){
    kk2=n;
    if(phong){
        drawAll();
    }
}
void d3::k3(double n){
    kk3=n;
    if(phong){
        drawAll();
    }
}
void d3::k4(int n){
    kk4=n;
    if(phong){
        drawAll();
    }
}
