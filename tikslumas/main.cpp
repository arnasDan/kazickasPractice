#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct verte
{
    double real;
    double aprox;
    bool match;
};

void skaityti(vector <verte> &Sk);
void isvesti(vector <verte> &Sk);

int main()
{
    vector <verte> Sk;
    skaityti(Sk);
    isvesti(Sk);
    return 0;
}

void skaityti(vector <verte> &Sk)
{
    int n;
    ifstream in("U1.txt");
    in >> n;
    Sk.resize(n);
    for (int i = 0; i < n; i++)
    {
        in >> Sk[i].real >> Sk[i].aprox;
        Sk[i].match = (Sk[i].real == Sk[i].aprox);
    }
}

int skirtumas(struct verte V)
{
    int i = 0, base;
    base = (int) V.aprox;
    V.aprox = (V.aprox - base) * 10;
    V.real = (V.real - base) * 10;
    while ((int) V.aprox == (int) V.real)
    {
        V.real *= 10;
        V.aprox *= 10;
        i++;
    }
    return i;
}

void isvesti(vector <verte> &Sk)
{
    cout << "Palyginimo rezultaltas:" << endl;
    for (int i = 0; i < Sk.size(); i++)
        if (Sk[i].match)
            cout << "T" << endl;
        else
            cout << "N " << skirtumas(Sk[i]) << endl;
}
