//
// Created by patryk on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

namespace nets {
    struct JsonValue {
        int liczba_i;
        string napis;
        double liczba_d;
        bool bool_vaLue;
        vector <int> v;
    };

    class JSON {
    private:
        JsonValue Json;
    public:
        JSON(int liczba_i) {
            this->Json.liczba_i = liczba_i;
        }

        JSON(string napis) {
            this->Json.napis = napis;
        }

        JSON(int liczba_d) {
            this->Json.liczba_d = liczba_d;
        }
        JSON(bool bool_value){
            this->Json.bool_vaLue=bool_value;
        }

        JSON(int liczba_v) {
            Json.v.emplace_back(liczba_v);
        }
        JSON(int liczba_i,string napis,double liczba_d,bool bool_value,int liczba_v){
            this->Json.liczba_i = liczba_i;
            this->Json.napis = napis;
            this->Json.liczba_d = liczba_d;
            this->Json.bool_vaLue=bool_value;
            Json.v.emplace_back(liczba_v);
        }
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
