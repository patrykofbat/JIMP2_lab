//
// Created by Patryk on 26.04.2017.
//

#include "Point.h"

int main(){
    point point2d(3,0);
    point3D point3d(2,0,0);
    point3D point3d_2(1,2,3);
    std::cout<<point2d.Distance(point3d)<<std::endl;
    &std::cout<<point3d_2<<std::endl;

    return 0;
}

/*Zadanie 1. Odpowiedz:Najpierw wywoluje sie konstruktor klasy bazowej, a nastepnie konstruktor klasy pochodnej.
 * Kolejność destruktrów 1.klasa pochodna 2.klasa bazowa*/

/*Zadanie 2. Odpowiedz:Gdy wykonamy wywolanie point2d.Distance(point3d) to otrzymamy odlegosc punktow(point2d i point 3d)
 * w plaszczyznie x i y */

/*Zadanie 3. Odpowiedz:Po wypisaniu obiketu w nastepujacy sposob &std::cout<<point3d_2<<std::endl; zostaly wypisane
 * skladowe x i y tego obiektu*/