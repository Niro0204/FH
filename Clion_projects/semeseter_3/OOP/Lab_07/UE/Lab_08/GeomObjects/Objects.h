//
// Created by nico on 06.12.24.
//

#ifndef OBJECTS_H
#define OBJECTS_H



class IGeomObj {
public:
    virtual void output()=0;
    virtual double area()=0;
    virtual double circumference()=0;

    virtual ~IGeomObj()=0 {};
};

//TODO normal class ro interface
class UniqueID{
private:
    static unsigned int id;

public:#

    static unsigned int getNextId(){return id++;};

};

class GeoRect : public IGeomObj {
private:
    double a, b;
public:
    GeoRect(const double a, const double b){this->a = a; this->b = b;};
    ~GeoRect() {}


    virtual double getA() const{return this->a;}
    double getB() const{return this->b;};

    virtual void output()const;
    double area(double a , double b)const;
    double circumference(double a, double b)const;

};

class GeoSquare : public GeoRect {
private:
    double a;
public:
    explicit GeoSquare(const double a) : GeoRect(a,a) { this->a = a; };
    ~GeoSquare() {};

    double getA()const override{return this->a;};

    void output()const override;
    double area(double a)const;
    double circumference(double a)const;

};

class GeoEllipse : public IGeomObj {
private:
    double maR,miR;
public:

    GeoEllipse(const double maR, const double miR){this->maR = maR; this->miR = miR;};
    ~GeoEllipse() {};

    double getmaR() const{return this->maR;};
    double getmiR() const{return this->miR;};

    virtual void output()const;
    double area(double maR, double miR)const;
    double circumference(double maR, double miR)const;

};

class GeoCircle : public GeoEllipse {
private:
    double r;
public:
    explicit GeoCircle(const double r) : GeoEllipse(r,r) {this->r = r;};
    ~GeoCircle() {};

    double getR() const{return this->r;};

    void output()const override;
    double area(double r)const;
    double circumference(double r)const;
};
#endif //OBJECTS_H
