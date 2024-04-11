#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void utworz(float*& t, const int n){
    t = new float[n];
    for(int i = 0; i < n; i++){
        t[i] = 0;
    }
}

void wypelnij(float*&t,const int n, float min, float max){
    srand(time(NULL));
    for(int i = 0; i < n; i++ ){
        t[i] = rand()+(max - min + 1) + min;
    }
}

void wypisz(float*&t, const int n){
    for(int i = 0; i < n; ++i){
        cout << t[i] << '\t';
    }
    cout << " " << endl;
}

int mail(string str){
    size_t pos = str.find("@");
    if(pos != string::npos){
        cout << "'@' znajduje sie na pozycji " << pos << endl;
        return true;
    } else {
        cout << "Nie ma symbolu '@' " << endl;
        return false;
    }
}

bool selector(const string file_out, const string file_in){
    ifstream input(file_in);
    ofstream output(file_out);
    string line;
    if(!input.is_open()){
        cout << "Wystapil blad." << endl;
        return false;
    }
    if(!output.is_open()){
        cout << "Wystapil blad." << endl;
        return false;
    }
    while(getline(input, line)){
        if(mail(line)){
            output << line << endl;
        }
    }
    output.clear();
    output.close();
    input.close();
    return true;
}




int main(int argc, char* argv[]){
    if(argc != 3 ){
        cout << "Min (mniej niz 0): " << endl;
        cout << "Max (wiekszy od zera): " << endl;
    } 

    float min = atof(argv[1]);
    float max = atof(argv[2]);
    float* t = nullptr;
    int n;
    string str;
    string file_out = "file_out.txt";
    string file_in = "file_in.txt";
    cout << "Podaj rozmiar tablicy. Rozmiar musi byc wiekszy od 0." << endl;
    cin >> n;
    cout << "Podaj string dla wyszukiwania '@': " << endl;
    cin >> str;
    if(n <= 0){
        cout << "Podaj rozmiar ponownie." << endl;
    }

    if(min < 0 && max > 0){
        utworz(t, n);
        wypelnij(t,n, min, max);
        wypisz(t,n);
        mail(str);
        if(selector(file_out, file_in)){
            cout << "Dane zostały zapisane w pliku " << file_out << endl;
        }
        else {
            cout << "Dane nie zostały zapisane - nieoczekiwany blad" << endl;
        }
    } 
    else {
        cout << "Podaj poprawny min albo max!" << endl;
    }
    delete t;
}