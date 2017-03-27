//
// Created by patryk on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include <map>
#include <regex>
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <ostream>
#include <regex>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;
using std::replace;
using std::regex_match;
namespace nets {

    class View {
    private:
        string phrase;
    public:
        View(string phrase);
        string Render(const unordered_map <string, string> &model) const;
    };

    View::View(string phrase){
        this->phrase=phrase;
    }

    string View::Render(const unordered_map<string, string> &model) const{
        string phrase_return;
        vector<string> hashes;
        phrase_return=phrase;
        std::regex pattern {R"((\{{2})(\w+)(\}{2}))"};
        for(int i=0;i<phrase_return.length();i++){
            if(phrase_return[i]=='{'){
                while(phrase_return[i]=='{'){
                    i++;
                }
                int begin=i-2;
                string new_phrase="";
                new_phrase+=phrase_return[i-1];
                new_phrase+=phrase_return[i-2];
                std::smatch matches;
                while(phrase_return[i]!='}'){
                    new_phrase+=phrase_return[i];
                    i++;
                }
                new_phrase+=phrase_return[i];
                new_phrase+=phrase_return[i+1];
                if(regex_match(new_phrase,matches,pattern)){
                    if (model.count(matches[2]) == 1) {
                        for (auto n:model) {
                            if(n.second[0]!='{') {
                                i=begin;
                                if (matches[2] == n.first) {
                                    phrase_return.replace(begin, matches[0].length(), n.second);

                                }
                            }
                            else if(n.second[0]=='{'){
                                if (matches[2] == n.first) {
                                    phrase_return.replace(begin, matches[0].length(), n.second);
                                }
                            }
                            
                        }
                    }
                    else if(model.count(matches[2])==0) {
                        i = begin;
                        phrase_return.erase(begin, matches[0].length());
                    }
                }


            }
        }


        return phrase_return;
    }

}
