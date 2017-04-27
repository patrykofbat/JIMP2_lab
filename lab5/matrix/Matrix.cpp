//
// Created by JA on 01.04.2017.
//

#include "matrix.h"

/*Matrix::Matrix(int wymiar_w,int wymiar_k){
    this->wymiar_w=wymiar_w;
    this->wymiar_k=wymiar_k;
}*/
Matrix::Matrix(string dane_wejsciowe, int wymiar_w, int wymiar_k) {
    this->dane_wejsciowe = dane_wejsciowe;
    this->wymiar_k = wymiar_k;
    this->wymiar_w = wymiar_w;
    for (int i = 0; i < wymiar_w; i++) {
        this->tablica_liczb[i] = new complex<double>[wymiar_k];
    }
}

void Matrix::Konwertuj() {
    int ilosc_srednikow = 0;
    int ilosc_spacji = 0;
    string cyfra_str;
    double cyfra_num_R;
    double cyfra_num_I;
    string cyfra_str_I;
    for (int i = 0; i < dane_wejsciowe.length() - 1; i++) {
        if (dane_wejsciowe[i] == '[' || dane_wejsciowe[i] == ']' || dane_wejsciowe[i]==',') {
            continue;
        }
        if (dane_wejsciowe[i] == ';') {
            ilosc_srednikow++;
            ilosc_spacji = 0;
        }
        if (dane_wejsciowe[i] == ' ') {
            ilosc_spacji++;
        }
        if (dane_wejsciowe[i] != ' ' && dane_wejsciowe[i] != ';') {
            bool imaginary = false;
            cyfra_str = "";
            cyfra_str_I = "";
            while (dane_wejsciowe[i] != ' ' && dane_wejsciowe[i] != ';') {
                if (dane_wejsciowe[i] == 'i') {
                    imaginary = true;
                    i++;
                }
                if (!imaginary) {
                    cyfra_str += dane_wejsciowe[i];
                    i++;
                }
                if (imaginary) {
                    cyfra_str_I += dane_wejsciowe[i];
                    i++;
                }
            }
            if (!imaginary) {
                double cyfra_I = 0;
                tablica_liczb[ilosc_srednikow][ilosc_spacji].imag(cyfra_I);
            } else {
                double cyfra_I = stod(cyfra_str_I);
                tablica_liczb[ilosc_srednikow][ilosc_spacji].imag(cyfra_I);
            }
            double cyfra_D = stod(cyfra_str);
            tablica_liczb[ilosc_srednikow][ilosc_spacji].real(cyfra_D);
            i--;
        }
    }
    /* for(int i=0;i<wymiar_w;i++){
         for(int j=0;j<wymiar_k;j++){
             cout<<tablica_liczb[i][j].real()<<"+"<<tablica_liczb[i][j].imag()<<"*i\t";
         }
         cout<<endl;
     }
 */
}

void Matrix::print() {
    for (int i = 0; i < wymiar_w; i++) {
        for (int j = 0; j < wymiar_k; j++) {
            cout << tablica_liczb[i][j].real() << "+" << tablica_liczb[i][j].imag() << "*i\t";
        }
        cout << endl;
    }
}

void Matrix::ustaw_element(int index_w, int index_k, complex<double> value) {
    tablica_liczb[index_w - 1][index_k - 1] = value;

}

void Matrix::pobierz_element(int index_w, int index_k) {
    cout << "Element o indeksie wiersza:" << index_w << " i indeksie kolumny:" << index_k << "="
         << this->tablica_liczb[index_w-1][index_k-1 ];
}

Matrix Matrix::add(Matrix M) {
    Matrix wynik(this->wymiar_w,this->wymiar_k);
    wynik.wymiar_k=this->wymiar_k;
    wynik.wymiar_w=this->wymiar_w;
    if((M.wymiar_k==wymiar_k)&&(M.wymiar_w==wymiar_w)){
        for(int i=0; i<M.wymiar_w;i++){
            for(int j=0;j<M.wymiar_k;j++){
                wynik.tablica_liczb[i][j]=(tablica_liczb[i][j]+M.tablica_liczb[i][j]);
            }

        }
        return wynik;

    }
    else{
        cout<<"Nie mozna dodac tych macierzy!\n";
    }

}

Matrix::Matrix(int wymiar_w,int wymiar_k) {
    for (int i = 0; i < wymiar_w; i++) {
        this->tablica_liczb[i] = new complex<double>[wymiar_k];
    }
}
Matrix::~Matrix(){
    delete [] tablica_liczb ;
}

Matrix::Matrix(const Matrix &M) {
    this->tablica_liczb=M.tablica_liczb;
    this->wymiar_w=M.wymiar_w;
    this->wymiar_k=M.wymiar_k;

}
Matrix Matrix::multiply(Matrix M){
    Matrix wynik(this ->wymiar_w,M.wymiar_k);
    if((this->wymiar_w==M.wymiar_w)){
        wynik.wymiar_w=this->wymiar_w;
        wynik.wymiar_k=this->wymiar_k;
        for (int i = 0; i < wymiar_w; i++) {
            for (int j = 0; j < wymiar_k; j++) {
              //  wynik.tablica_liczb[i][j] = (0,0);
                for (int k = 0; k < wymiar_w; k++) {
                    wynik.tablica_liczb[i][j] =
                            wynik.tablica_liczb[i][j] + (this->tablica_liczb[i][k]) * M.tablica_liczb[k][j];
                }
            }
        }
    }
    return wynik;


}
Matrix Matrix::power(int n){
    if(n==1){
        return *this;
    }
    else{
        return  this->multiply(*this);
    }
}

Matrix Matrix::substract(Matrix M) {
    Matrix wynik(this->wymiar_w, this->wymiar_k);
    wynik.wymiar_k = this->wymiar_k;
    wynik.wymiar_w = this->wymiar_w;
    if ((M.wymiar_k == wymiar_k) && (M.wymiar_w == wymiar_w)) {
        for (int i = 0; i < M.wymiar_w; i++) {
            for (int j = 0; j < M.wymiar_k; j++) {
                wynik.tablica_liczb[i][j] = (tablica_liczb[i][j] + M.tablica_liczb[i][j]);
            }

        }
        return wynik;

    } else {
        cout << "Nie mozna dodac tych macierzy!\n";
    }
}
