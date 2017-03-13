//
// Created by patryk on 09.03.17.
//

#include "Polybius.h"

using namespace std;



string PolybiusCrypt(string message)
{
    string message_crypted="";
    transform(message.begin(),message.end(),message.begin(),::tolower);
    char polybius_crypt_i[][5]={{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    char polybius_crypt_j[][5]={{'a','b','c','d','e'},{'f','g','h','j','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    int j=0;
    int k=0;
    string tmp_j;
    string tmp_k;
    for(int i=0;i<=message.length()-1;i++){
        j=0;
        while(j<=4){
            for(k=0;k<5;k++) {
                if ((message[i] == polybius_crypt_i[j][k])&& (message[i]=='i')) {
                    tmp_j = to_string(j + 1);
                    tmp_k = to_string(k + 1);
                    message_crypted += tmp_j;
                    message_crypted += tmp_k;

                }
                else if ((message[i] == polybius_crypt_j[j][k])&& (message[i]=='j')) {
                    tmp_j = to_string(j + 1);
                    tmp_k = to_string(k + 1);
                    message_crypted += tmp_j;
                    message_crypted += tmp_k;

                }
                else{
                    if ((message[i] == polybius_crypt_i[j][k])) {
                        tmp_j = to_string(j + 1);
                        tmp_k = to_string(k + 1);
                        message_crypted += tmp_j;
                        message_crypted += tmp_k;

                    }



                }
            }
            j++;
        }

    }
    return message_crypted;

}
string PolybiusDecrypt(string crypted){
    char polybius_crypt_i[][5]={{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    string message_decrypted;
    string tmp_crypted_k;
    string tmp_crypted_j;
    int k;
    int j;
    int i=0;
    while(i<=crypted.length()-1){
        tmp_crypted_k = crypted[i];
        tmp_crypted_j = crypted[i+1];
        k=stoi(tmp_crypted_k);
        j=stoi(tmp_crypted_j);
        message_decrypted += polybius_crypt_i[k-1][j-1];
        i+=2;


    }
    return message_decrypted;

}

int main(int argc,char *argv[]){
    ifstream myfile(argv[1]);
    ofstream myfile_2(argv[2], ios_base::in | ios_base::app);
    string word;
    if(argc<4)
        cout<<"Brak parametrow";
    else{
        if(*argv[3]=='1'){
            if(!myfile)
                cout << "Nie można otworzyć pliku!" << endl;

            while(myfile >> word)
                myfile_2<<PolybiusCrypt(word)<<endl;


            myfile.close();
            myfile_2.close();

        }
        else if(*argv[3]=='0'){
            if(!myfile)
                cout << "Nie można otworzyć pliku!" << endl;

            while(myfile >> word)
                myfile_2<<PolybiusDecrypt(word)<<endl;


            myfile.close();
            myfile_2.close();
        }

    }


    return 0;
}
/*Gdy skompilujemy pogram Polybius.cpp z lini polecen to pogram dziala ,jednakze testow nie
 * przchodzi*/







