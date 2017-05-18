//
// Created by Patryk on 10.05.2017.
//
#include "Serialization.h"


int main() {
    std::stringstream out;

    academia::JsonSerializer serialize(&out);
    academia::Room room {20,"h-24",academia::Room::Type::COMPUTER_LAB};
    room.Serialize(&serialize);
    std::cout;


    return 0;
}

