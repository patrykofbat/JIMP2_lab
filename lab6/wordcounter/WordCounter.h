//
// Created by Patryk on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H
#include <string>
#include <regex>
#include <vector>
#include <list>
#include <fstream>
#include <ostream>
#include <iostream>


using std::string;

class Word;

class Counts;

class WordCounter {
public:
    std::list<std::pair<Word, Counts>> lista;
public:
    WordCounter(string sciezka);

    friend class Word;

    friend class Counts;

    int operator[](string request);

    friend std::ostream &operator<<(std::ostream *out,WordCounter s1);

    ~WordCounter();
};


class Word {
public:
    string word;
public:
    Word(string Word) : word(Word) {}

    friend class WordCounter;


};

class Counts {
public:
    int count = 0;
public:
    Counts &operator++() {
        ++count;
        return *this;
    }
    bool operator<(Counts s1);

    bool operator>(Counts s1);

    bool operator==(Counts s1);

    friend class WordCounter;

    Counts() { ++*this; };


};

#endif //JIMP_EXERCISES_WORDCOUNTER_H
