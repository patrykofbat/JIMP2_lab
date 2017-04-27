//
// Created by Patryk on 26.04.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H
#include <iostream>
#include <cmath>
#include <ostream>

class point{
public:
    point(){std::cout<<"wtf"<<std::endl;};
    point(double x,double y);
    ~point();
    double GetX()const{return x;};
    double GetY()const{return y;};
    double Distance(const point &other)const;
    friend std::ostream &operator<< (std::ostream *out, const point &other);


private:
    double x ,y;
};

class point3D : public point{
public:
    point3D(double x,double y, double z):point(x,y){
        this->z=z;
        std::cout<<"utworzono 3d"<<std::endl;
    };
    ~point3D(){std::cout<<"narka 3d"<<std::endl;};

    double GetZ()const {return z;};
private:
    double z;

};

#endif //JIMP_EXERCISES_POINT_H
