//
// Created by patryk on 02.03.17.
//

#include "DoubleBasePalindromes.h"
#include <cmath>
using namespace std;


int is_bin_pal(int value){
    int reszta;
    int status=1;
    int k=0;
    string cyfra;
    string napis;
    for(int i=value;i>=1;i=(i/2)){
        reszta=i%2;
        cyfra=to_string(reszta);
        napis+=cyfra;
    }
    for(int j=napis.length()-1;j>=0;j--){
        if(napis[j] != napis[k]) {
            status = 0;
            break;
        }
        k++;

    }
    return status;


}
int is_dec_pal(int value){
    string str_dec;
    str_dec=to_string(value);
    int i=0;
    int status=1;
    for(int j=str_dec.length()-1;j>=0;j--)
    {
        if(str_dec[j] != str_dec[i]){
            status=0;
            break;
        }
        i++;
    }
    return status;


}
uint64_t DoubleBasePalindromes(int max_value_exculsive){
    int max=max_value_exculsive;
    uint64_t suma=0;
    for(int i=1;i<=max;i++){
        if(is_bin_pal(i)==1 && is_dec_pal(i)==1)
            suma=suma+i;
    }

    return  suma;

}