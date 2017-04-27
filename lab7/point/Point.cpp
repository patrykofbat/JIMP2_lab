//
// Created by Patryk on 26.04.2017.
//

#include "Point.h"

point::point(double x, double y) {
    this->x=x;
    this->y=y;
    std::cout<<"Created x and y "<<std::endl;
}
point::~point() {
    std::cout<<"x and y has been destroyed"<<std::endl;
}

double point::Distance(const point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

std::ostream &operator<< (std::ostream *out, const point &other) {
    return (*out)<<other.GetX()<<" "<<other.GetY();
}