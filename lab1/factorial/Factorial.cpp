//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  int silnia=1;
    for(int i=value;i>=1;i--){
        silnia=silnia*i; /*iteracyjn*/
    }
    return silnia;
}
