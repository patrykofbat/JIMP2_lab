//
<<<<<<< HEAD
// Created by JA on 27.03.2017.
=======
// Created by patryk on 21.03.17.
>>>>>>> origin/master
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
<<<<<<< HEAD
#include <experimental/optional>
#include <sstream>
using ::std::literals::operator""s;
using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::string;


namespace nets {

    class JsonValue {
    public:
        JsonValue(int json_int);

        JsonValue(map<string, JsonValue> map_json);

        JsonValue(bool json_bool);

        JsonValue(vector<JsonValue> json_vec);

        JsonValue(string json_str);

        JsonValue(float json_float);

        JsonValue ValueByName (string test);

        string ToString();



    public:
        int json_int;
        float json_float;
        bool json_bool;
        vector<JsonValue> json_vec;
        string json_str;
        map<string, JsonValue> map_json;

    };



=======
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
>>>>>>> origin/master
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
