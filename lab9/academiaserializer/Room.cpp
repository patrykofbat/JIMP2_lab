//
// Created by Patryk on 17.05.2017.
//

#include "Room.h"

namespace academia {
    void Room::Serialize(Serializer *in) const{
        in->Header("Room");
        in->IntegerField("id", id);
        in->Comma("name");
        in->StringField("name", name);
        in->Comma("name");
        in->StringField("type", enum_table[int(this->type)]);
        in->Footer("Room");


    }
}
