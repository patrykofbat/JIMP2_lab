//
// Created by Patryk on 17.05.2017.
//

#ifndef JIMP_EXERCISES_ROOM_H
#define JIMP_EXERCISES_ROOM_H

#include "Serializer.h"

namespace academia {
    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB = 0,
            LECTURE_HALL,
            CLASSROOM
        };
    private:
        int id;
        std::string name;
        Type type;
        std::vector<std::string> enum_table={"COMPUTER_LAB","LECTURE_HALL", "CLASSROOM"};

    public:
        Room(int ID, const std::string &Name, Type type) : id(ID), name(Name), type(type) {}

        ~Room() {}

        void Serialize(Serializer *in)const ;

    };
}


#endif //JIMP_EXERCISES_ROOM_H
