//
// Created by Patryk on 31.03.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

using std::experimental::string_view;

namespace pool{
class TextPool{
private:
    std::set<string_view> Pool;
public:
    TextPool();

    TextPool(const std::initializer_list<string_view> pool_);

    TextPool(TextPool &&xxx);

    TextPool&operator=(TextPool &&xxx);

    ~TextPool();

    string_view Intern(const std::string &str);

    size_t StoredStringCount() const;


};
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
