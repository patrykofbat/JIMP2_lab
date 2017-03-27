//
// Created by JA on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
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



}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
