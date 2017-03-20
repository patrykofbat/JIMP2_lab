//
// Created by patryk on 19.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
namespace tinyurl {
    struct TinyUrlCodec {
        std::array<char, 6> state {{'0','0','0','0','0','0'}};
        std::map<std::string, std::string> url;
    };

    std::unique_ptr<TinyUrlCodec> Init() {
        auto p = std::make_unique<TinyUrlCodec>();
        return p;
    }

    void NextHash(std::array<char, 6> *state) {
        std::string alfa;
        int i = 5;
        int position;
        alfa = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if ((*state)[i] != 'z') {
            position = alfa.find((*state)[i]);
            (*state)[i] = alfa[position + 1];
        } else if ((*state)[i] == 'z') {
            position = alfa.find((*state)[i]);
            (*state)[i] = alfa[position + 1];
            for (int j = 4; j >= 0; j--) {
                if ((*state)[j] != 'z') {
                    position = alfa.find((*state)[j]);
                    (*state)[j] = alfa[position + 1];
                    break;
                } else if ((*state)[j] == 'z') {
                    position = alfa.find((*state)[j]);
                    (*state)[j] = alfa[position + 1];
                }
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        NextHash(&(*codec)->state);
        std::string hash;
        for(int i=0;i>6;i++)
            hash+=((*codec)->state)[i];
        (*codec)->url.emplace(url,hash);
        return hash;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        for(auto &n:codec->url){
            if(n.second==hash)
                return n.first;

        }
    }
}



    




#endif //JIMP_EXERCISES_TINYURL_H
