#include <iostream>
using namespace std;


//void wypisz_tablice_2d(unsigned int tab_2d[][], unsigned int wierszy, unsigned int kolumny){
    //for(int i = 0; i < wierszy, i++){
        //for(j = 0; j < kolumny, j++){
            
        //}
    //}
//}

int ile_wystapien_znaku(string zrodlo, char znak){
    unsigned int ile_wystapien = 0;
    for(int i = 0; i < zrodlo.length(); i++){ 
        if(zrodlo[i] == znak){
            ile_wystapien += 1;
        }
    }    
    return ile_wystapien;
    
}

int znak_na_numer(char znak, int n){
    int pozycja = 111;
    char alfabet_angielski[] = {'a', 'b', 'c', 'd' , 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for(int i = 0; i < n; ++i ){
        if(alfabet_angielski[i] == znak){
            pozycja = i;
            break;
        }
    }
    return pozycja;
}

void statystyka(unsigned int* tablica, string napis){
    //for(int i = 0; i < tablica.length; ++i){
        //tablica[i] = 0;
    //}
    for (int i = 0; i < tablica.length; ++i){
        char znak = tablica[i];
        tablica[i] = ile_wystapien_znaku(napis,znak);
    }
}

int wypisz(unsigned int* tablica){
    for(int i = 0; i < tablica.length; ++i){
        cout << T[i] << endl;
    }
}


int main(int argc, char* argv[]){
    if(argc !=  4){
        cout << "Podaj string, podaj znak dla stringu, podaj znak dla alfabetu " << endl;
    }


    string str1 = argv[1];
    char* znak1 = argv[2];
    char* znak2 = argv[3];

    string napis_dla_statyst;
    cout << "Podaj napis dla statystyki: " << endl;
    cin >> napis_dla_statyst;
    char tablica[26] = {'a', 'b', 'c', 'd' , 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    cout << wypisz(tablica) << endl;


    cout << "Znak wystopi " << ile_wystapien_znaku(str1, *znak1) << endl;
    if (s != -1) {
        cout << "Znak " << znak2 << " występuje na pozycji " << s << endl;
    } else {
        cout << "Podany znak nie został znaleziony w alfabecie angielskim." << endl;
    }
}