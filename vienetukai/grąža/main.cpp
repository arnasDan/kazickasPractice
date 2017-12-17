#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct nom
{
    int n;
    int k;
};

void skaityti(int &sk, vector <nom> &Png);
void ieskotiNominalu(int &sk, vector <nom> &Png);
void isvesti(vector <nom> Png);
bool sortas(struct nom a, struct nom b);

int main()
{
    int sk;
    vector <nom> Png;
    skaityti(sk, Png);
    sort(Png.begin(), Png.end(), sortas);
    ieskotiNominalu(sk, Png);
    isvesti(Png);
    return 0;
}

void skaityti(int &sk, vector <nom> &Png)
{
    int n;
    ifstream in("U2.txt");
    in >> n;
    Png.resize(n);
    for (int i = 0; i < Png.size(); i++)
    {
        in >> Png[i].n;
        Png[i].k = 0;
    }
    in >> sk;
}

void ieskotiNominalu(int &sk, vector <nom> &Png)
{
    for (int i = 0; i < Png.size(); i++)
    {
        if (Png[i].n <= sk)
        {

            Png[i].k += sk / Png[i].n;
            sk -= (sk / Png[i].n) * Png[i].n;
            if (sk == 0)
                break;
        }
        else if (i != 0)
        {
            while (Png[i].n > sk)
            {
                sk += Png[i - 1].n;
                Png[i - 1].k--;
            }
            i--;
        }
    }
}

bool sortas(struct nom a, struct nom b)
{
    return (a.n > b.n);
}

void isvesti(vector <nom> Png)
{
    for (int i = 0; i < Png.size(); i++)
        if (Png[i].k > 0)
            cout << Png[i].k << " " << Png[i].n << endl;
}
