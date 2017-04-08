//
// Created by Patryk on 08.04.2017.
//

#include "WordCounter.h"


WordCounter::WordCounter(string sciezka) {
    string word;
    std::fstream file;
    std::vector<std::pair<Word, Counts>> v;
    std::regex pattern(R"([a-zA-Z0-9]+)");
    file.open(sciezka);
    if (!file)
        std::cout << "can't open" << std::endl;

    while (file >> word) {
        std::smatch matches;
        if (std::regex_search(word, matches, pattern)) {
            Word tmp(matches[0]);
            Counts liczba;
            auto p1 = std::make_pair(tmp, liczba);
            v.emplace_back(p1);

        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].first.word == v[j].first.word) {
                ++(v[i].second);
                v[j].first.word = ".";
            }

        }
        if (v[i].first.word != ".")
            this->lista.push_back(v[i]);
    }


    file.close();
}


WordCounter::~WordCounter() {

}

int WordCounter::operator[](string request) {
    int empty = 0;
    for (auto n:this->lista) {
        if (n.first.word == request)
            return n.second.count;
    }
    return empty;
}

bool Counts::operator<(Counts s1) {
    if (this->count < s1.count)
        return true;
    return false;
}

bool Counts::operator>(Counts s1) {
    if (this->count > s1.count)
        return true;
    return false;
}

bool Counts::operator==(Counts s1) {
    if(this->count == s1.count)
        return true;
    return false;
}

std::ostream & operator<<(std::ostream *out,WordCounter s1){
    int amountOfWords = 0;
    std::list<std::pair<int,string>> new_list;
    for(auto n:s1.lista){
        amountOfWords +=n.second.count;
        auto p1=std::make_pair(n.second.count,n.first.word);
        new_list.push_back(p1);
    }
    new_list.sort();
    new_list.reverse();
    std::cout<<"Ilosc slow : "<<amountOfWords<<std::endl;
    for(auto p:new_list){
        (*out)<<"Slowo: "<<p.second<<" || "<<"Liczebnosc: "<<p.first<<std::endl;
    }
    return (*out);




}
