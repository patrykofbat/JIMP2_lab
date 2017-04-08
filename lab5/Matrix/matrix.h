//
// Created by JA on 01.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#endif //JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::complex;
using std::vector;
using std::map;
using std::complex;
using namespace std::literals;
using std::string;
using std::stod;
using std::stoi;
class Matrix{
private:
    int wymiar_w;
    int wymiar_k;
    string dane_wejsciowe;
    complex <double> **tablica_liczb=new complex<double> *[wymiar_k];
public:
    Matrix(string dane_wejsciowe,int wymiar_w,int wymiar_k);

    Matrix(int wymiar_w,int wymiar_k);
    ~Matrix();
    void Konwertuj();
    void print();
    void ustaw_element(int index_w,int index_k,complex<double> value);
    void pobierz_element(int index_w,int index_k);
    Matrix add(Matrix M);
    Matrix(const Matrix &M);
    Matrix multiply(Matrix M);
    Matrix power(int n);
    Matrix substract(Matrix M);

};

