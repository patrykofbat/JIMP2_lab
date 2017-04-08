//
// Created by JA on 01.04.2017.
//
#include "matrix.h"
int main() {
/*   int ilosc_srednikow = 0;
    int ilosc_spacji = 0;
    complex<double> tablica[3][3];
    string nazwa = "0i-95 -5i5 7;4i6 3 0i9;8i7 5i4 4i9";
    complex<double> liczba;
    for (int i = 0; i <= nazwa.length() - 1; i++) {
        if (nazwa[i] == ';') {
            ilosc_srednikow++;
            ilosc_spacji = 0;
        }
        if (nazwa[i] == ' ') {
            ilosc_spacji++;
        }
        if (nazwa[i] != ';' && nazwa[i] != ' ') {
            bool imaginary = false;
            string cyfra_str = "";
            string cyfra_str_I = "";
            while (nazwa[i] != ' ' && nazwa[i] != ';') {
                if(nazwa[i]=='i') {
                    imaginary = true;
                    i++;
                }
                if(!imaginary) {
                    cyfra_str += nazwa[i];
                    i++;
                }

                if(imaginary){
                    cyfra_str_I+=nazwa[i];
                    i++;
                }
                }
            if(!imaginary) {
                double cyfra_I = 0;
                tablica[ilosc_srednikow][ilosc_spacji].imag(cyfra_I);
            }
            else{
                double cyfra_I=stod(cyfra_str_I);
                tablica[ilosc_srednikow][ilosc_spacji].imag(cyfra_I);
                 }
            i--;
        }
    }*/
//cout<<tablica[0][0];
    complex<double> z(10,10);
    Matrix m("[1i1, 1i0;1i5 1i0]",2,2);
    Matrix m2("[1i0 1i0;1i0 1i0]",2,2);
    m.Konwertuj();
    m2.Konwertuj();
   // m.print();
    Matrix wynik(m.add(m2));
    m.print();


    return 0;
}