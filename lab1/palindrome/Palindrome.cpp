//
// Created by patryk on 02.03.17.
//

#include "Palindrome.h"
#include <iostream>
#include <string>
using namespace std;


bool is_palindrome(string str){
    int status=1;
    int j=0;
    for(int i=str.length()-1;i>=0;i--) {
        if (str[i] != str[j])
            status = 0;
            j++;
    }
        if(status==1)
            return true;
        if(status==0)
            return false;
    }