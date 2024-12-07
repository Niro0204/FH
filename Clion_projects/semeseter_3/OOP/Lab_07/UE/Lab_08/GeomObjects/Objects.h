//
// Created by nico on 06.12.24.
//

#ifndef OBJECTS_H
#define OBJECTS_H



class IGeomObj {
public:
    virtual void output() const =0;
    virtual double area() const=0;
    virtual double circumference() const =0;

    virtual ~IGeomObj()=0;
};

inline IGeomObj::~IGeomObj() {}

class IUniqueID {
public:
    virtual unsigned int getID() const = 0;
    virtual ~IUniqueID() = default;
};

class UniqueID {
private:
    static unsigned int id;
public:
    static unsigned int getNextId() { return id++; }
};

class GeoRect : public IGeomObj, public IUniqueID {
private:
    double a, b;
    unsigned int id;

public:
    GeoRect(const double a, const double b) : id(UniqueID::getNextId()) {this->a = a; this->b = b;};
    ~GeoRect() {}


    virtual double getA() const{return this->a;}
    double getB() const{return this->b;};
    unsigned int getID() const override{return this->id;};

    void output()const override;
    double area()const override;
    double circumference()const override;

};

class GeoSquare : public GeoRect{
private:
    double a;

public:
    explicit GeoSquare(const double a) : GeoRect(a,a) { this->a = a; };
    ~GeoSquare() {};

    double getA()const override {return this->a;};

    void output()const override;
    double area()const override;
    double circumference()const override;

};

class GeoEllipse : public IGeomObj, public IUniqueID {
private:
    double maR,miR;
    unsigned int id;
public:

    GeoEllipse(const double maR, const double miR) : id(UniqueID::getNextId()) {this->maR = maR; this->miR = miR;};
    ~GeoEllipse() {};

    double getmaR() const{return this->maR;};
    double getmiR() const{return this->miR;};
    virtual unsigned int getID() const{return this->id;};

    void output()const override;
    double area()const override;
    double circumference()const override;

};

class GeoCircle : public GeoEllipse{
private:
    double r;

public:
    explicit GeoCircle(const double r) : GeoEllipse(r,r) {this->r = r;};
    ~GeoCircle() {};

    double getR() const{return this->r;};

    void output()const override;
    double area()const override;
    double circumference()const override;
};
#endif //OBJECTS_H
