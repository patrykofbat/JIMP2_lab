//
// Created by patryk on 02.03.17.
//

#include "DoubleBasePalindromes.h"


using namespace std;

int main(){
    uint64_t suma=0;
   for(int i=1;i<=1000000;i++){
       if(is_bin_pal(i)==1 && is_dec_pal(i)==1)
           suma+=i;

   }
    cout<<suma;
    return 0;


}