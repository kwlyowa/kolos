#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int *utworz(const int n)
{
    int *t = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        t[i] = 0;
    }

    return t;
}

void wypelnij(int *t, const int n, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        t[i] = min + rand() % abs(max - min + 1);
    }
}

void wypisz(int *t, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << t[i] << '\t';
    }
}

bool mail(string str)
{
    char znak = '@';
    size_t poz = str.find(znak);
    if (poz != string ::npos)
    {
        cout << "Jest adresem mailowym" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void selektor(const char *file_in, const char *file_out)
{
    ifstream input("file_in.txt");
    ofstream output("file_out.txt");
    if (!input.is_open())
    {
        cout << "Wystapil blad" << endl;
    }
    if (!output.is_open())
    {
        cout << "Wystapil blad" << endl;
    }

    char *line;
    while (input >> line)
    {
        if (mail(line))
        {
            output << line << endl;
        }
    }
    input.close();
    output.close();
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Podaj wartosci w takiej kolejnosci: <liczba min>(mniejsza od 0), <liczba max>(wieksza od 0)." << endl;
    }

    int min, max;

    min = atoi(argv[1]);
    max = atoi(argv[2]);

    int n;
    cout << "Podaj rozmiar dla tablicy. Rozmiar musi byc wiekszy od 0." << endl;
    cin >> n;
    int *t = utworz(n);

    if (n > 0 && min < 0 && max > 0)
    {
        cout << "Wartosci sa poprawny" << endl;
    }
    else
    {
        do
        {
            cout << "Podaj poprawny wartosci!" << endl;
            cout << "Podaj rozmiar dla tablicy. Rozmiar musi byc wiekszy od 0." << endl;
            cin >> n;
            cout << "Podaj liczbe minimalna. Musi byc mniejsza od 0." << endl;
            cin >> min;
            cout << "Podaj liczbe maksymalna. Musi byc wieksza od 0" << endl;
            cin >> max;
        } while (!(n > 0 && min < 0 && max > 0));
    }

    wypelnij(t, n, min, max);
    //wypisz(t, n);
    //t = nullptr;
    delete[] t;
    t = nullptr;

    //const char *file_in = "file_in.txt";
    //const char *file_out = "file_out.txt";
    //selektor(file_in, file_out);

}
