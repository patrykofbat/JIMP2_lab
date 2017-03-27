//
<<<<<<< HEAD
// Created by JA on 27.03.2017.
//

#include "SimpleJson.h"
using namespace nets;


JsonValue::JsonValue(int json_int) {
    this->json_int = json_int;
}

JsonValue::JsonValue(bool json_bool) {
    this->json_bool = json_bool;
}

JsonValue::JsonValue(vector<JsonValue> json_vec) {
    this->json_vec = json_vec;

}

JsonValue::JsonValue(string json_str) {
    this->json_str = json_str;
}

JsonValue::JsonValue(float json_float) {
    this->json_float = json_float;
}

JsonValue::JsonValue(map<string, JsonValue> map_json) {
    this->map_json = map_json;
}
JsonValue JsonValue:: ValueByName (string test) {
    for (auto p : map_json) {
        if(p.first==test)
            return JsonValue(p.second);
    }
}







=======
// Created by patryk on 21.03.17.
//

namespace nets{



}
>>>>>>> origin/master
