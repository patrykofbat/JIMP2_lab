//
// Created by patryk on 13.03.17.
//



#include "XorCypherBreaker.h"

using namespace std;


struct info {
    string key;
    int liczba;
};

int szukajWszystkichFraz(string & tekst, string szukanaFraza )
{
    size_t znalezionaPozycja = tekst.find( szukanaFraza );
    int suma=0;
    if( znalezionaPozycja == string::npos )
    {

        return suma;
    }

    do
    {

        znalezionaPozycja = tekst.find( szukanaFraza, znalezionaPozycja + szukanaFraza.size() );
        suma+=1;
    } while( znalezionaPozycja != string::npos );
    return suma;

}






}
void PrintMap(const map<char,int> &v) {
    bool first = true;
    for(const auto &n : v) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n.first << " -> " << n.second;

    }
    cout<<endl;
}



int main() {
    string alfabet = "abcdefghijklmnopqrstuvwxyz";
    string decrypted;
    map<string, info> informacje;
    vector<string> dictionary
            {"the", "of", "and", "to", "a", "in", "is", "you", "are", "for", "that", "or", "it", "as", "be", "on",
             "your", "with", "can", "have", "this", "an", "by", "not", "but", "at", "from", "I", "they", "more",
             "will", "if", "some", "there", "what", "about", "which", "when", "one", "their", "all", "also",
             "how", "many", "do", "has", "most", "people", "other", "time", "so", "was", "we", "these", "may",
             "like", "use", "into", "than", "up", "out", "who", "them", "make", "because", "such", "through",
             "get", "work", "even", "different", "its", "no", "our", "new", "film", "just", "only", "see", "used",
             "good", "water", "been", "need", "should", "very", "any", "history", "often", "way", "well", "art",
             "know", "were", "then", "my", "first", "would", "money", "each", "over", "world", "information", "map",
             "find", "where", "much", "take", "two", "want", "important", "family", "those", "example", "while",
             "he", "look", "government", "before", "help", "between", "go", "own", "however", "business", "us",
             "great", "his", "being", "another", "health", "same", "study", "why", "few", "game", "might", "think",
             "free", "too", "had", "hi", "right", "still", "system", "after", "computer", "best", "must", "her",
             "life", "since", "could", "does", "now", "during", "learn", "around", "usually", "form", "meat", "air",
             "day", "place", "become", "number", "public", "read", "keep", "part", "start"};
    vector<char> cryptogram
            {93, 65, 76, 47, 7, 25, 15, 4, 76, 34, 0, 30, 30, 6, 31, 76, 12, 13, 2, 79, 24, 13, 4, 9, 76, 28, 15, 30,
             10, 9,
             2, 28, 4, 3, 27, 76, 3, 9, 76, 4, 6, 31, 76, 13, 0, 25, 10, 76, 31, 12, 30, 9, 10, 2, 76, 0, 10, 76, 11, 9,
             13,
             27, 4, 76, 93, 66, 76, 63, 30, 3, 8, 30, 13, 2, 1, 9, 29, 76, 68, 1, 3, 25, 1, 66, 69, 79, 45, 76, 31, 9,
             30, 28,
             3, 2, 79, 27, 4, 0, 76, 10, 6, 20, 9, 11, 76, 13, 79, 28, 30, 0, 14, 0, 10, 1, 76, 22, 3, 25, 79, 8, 3, 79,
             2, 3,
             27, 76, 7, 1, 3, 27, 79, 21, 3, 26, 76, 4, 14, 26, 9, 67, 76, 5, 1, 76, 13, 79, 27, 13, 22, 76, 21, 0, 25,
             76,
             11, 3, 76, 1, 3, 24, 79, 25, 2, 11, 9, 30, 28, 24, 13, 1, 8, 66};
    map<char, int> asci = {};
    for (int i = 0; i <= alfabet.length() - 1; i++) {
        asci.emplace(alfabet[i], i + 97);
    }
    for (int j = 97; j <= 122; j++) {               /*all possibilites of permutation*/
        for (int k = 97; k <= 122; k++) {
            for (int l = 97; l <= 122; l++) {
                for (size_t d = 0; d < cryptogram.size(); d + 3) {
                    int one = cryptogram[d] ^j;
                    int two = cryptogram[d + 1] ^k;
                    int three = cryptogram[d + 2] ^l;
                    for (auto &p :asci) {
                        if (p.second == one)
                            decrypted += p.first;
                    }
                    for (auto &p :asci) {
                        if (p.second == two)
                            decrypted += p.first;
                    }
                    for (auto &p :asci) {
                        if (p.second == three)
                            decrypted += p.first;
                    }
                    for (auto n:dictionary) {
                        int liczebnosc = szukajWszystkichFraz(decrypted, n);
                        if (liczebnosc != 0) {
                            info info_2;
                            info_2.liczba = liczebnosc;
                            string key = "";
                            for (auto &g :asci) {
                                if (g.second == j)
                                    key += g.first;
                            }
                            for (auto &g :asci) {
                                if (g.second == k)
                                    key += g.first;
                            }
                            for (auto &g :asci) {
                                if (g.second == k)
                                    key += g.first;

                                info_2.key = key;
                                informacje.emplace(n, info_2);


                            }
                        }


                    }


                }
            }

        }


    }

}