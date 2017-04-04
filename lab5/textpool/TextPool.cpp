//
// Created by Patryk on 31.03.2017.
//

#include "TextPool.h"
using namespace pool;
using std::move;

pool::TextPool::TextPool() {}

pool::TextPool::~TextPool() {}


string_view TextPool::Intern(const std::string &str){
    string_view str_v = str;
    if(Pool.count(str_v)==1)
            return str_v;
    else {
        Pool.emplace(str_v);
        return str_v;
    }

}
size_t TextPool::StoredStringCount() const{
    return Pool.size();
}


TextPool::TextPool(const std::initializer_list<string_view> pool_){
    Pool=pool_;
}

TextPool::TextPool(TextPool &&xxx) {
    std::swap(Pool,xxx.Pool);
}

TextPool & TextPool::operator=(TextPool &&xxx){
    if(this ==&xxx)          /*x=move(x)-przerzucanie tego samego obiektu*/
        return *this;
    std::swap(Pool,xxx.Pool);
    return *this;

}






