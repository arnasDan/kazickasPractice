#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct siunta
{
    int nr;
    int prT;
    int t;
    int mase;
    int prior;
    int ivertis()
    {
        return (prior * 2 + t + 10 * (t >= 15));
    }
};

void skaityti(vector <siunta> &Siuntos);
void setTime(vector <siunta> &Siuntos, int t);
void plukdymas(vector <siunta> Siuntos, vector <siunta> &issiustosSiuntos);
void isvesti(vector <siunta> Siuntos);
int bestChoice(vector <siunta> Siuntos);

int main()
{
    vector <siunta> Siuntos;
    vector <siunta> issiustosSiuntos;
    skaityti(Siuntos);
    plukdymas(Siuntos, issiustosSiuntos);
    isvesti(issiustosSiuntos);
    return 0;
}

void skaityti(vector <siunta> &Siuntos)
{
    int n;
    ifstream in("U2.txt");
    in >> n;
    Siuntos.resize(n);
    for (int i = 0; i < n; i++)
    {
        in >> Siuntos[i].t;
        Siuntos[i].nr = i + 1;
        Siuntos[i].prT = Siuntos[i].t;
    }
    for (int i = 0; i < n; i++)
        in >> Siuntos[i].prior;
    for (int i = 0; i < n; i++)
        in >> Siuntos[i].mase;
}

void plukdymas(vector <siunta> Siuntos, vector <siunta> &issiustosSiuntos)
{
    int best, time, lim;
    while (Siuntos.size() > 0)
    {
        time = 3;
        if (Siuntos.size() >= 3)
            lim = 3;
        else
            lim = Siuntos.size();
        for (int i = 0; i < lim; i++)
        {
            best = bestChoice(Siuntos);
            issiustosSiuntos.push_back(Siuntos[best]);
            time += Siuntos[best].mase;
            Siuntos.erase(Siuntos.begin() + best);
        }
        setTime(Siuntos, time);
    }
}

void setTime(vector <siunta> &Siuntos, int t)
{
    for (int i = 0; i < Siuntos.size(); i++)
        Siuntos[i].t += t;
}

int bestChoice(vector <siunta> Siuntos)
{
    int bestI = 0;
    for (int i = 1; i < Siuntos.size(); i++)
    {
        if ((Siuntos[i].ivertis() > Siuntos[bestI].ivertis()) ||
            (Siuntos[i].ivertis() == Siuntos[bestI].ivertis() && Siuntos[i].t > Siuntos[bestI].t ) ||
            (Siuntos[i].ivertis() == Siuntos[bestI].ivertis() && Siuntos[i].t == Siuntos[bestI].t && Siuntos[i].nr < Siuntos[bestI].nr))
            bestI = i;
    }
    return bestI;
}

void isvesti(vector <siunta> Siuntos)
{
    for (int i = 0; i < Siuntos.size(); i++)
        cout << Siuntos[i].nr << " ";
    cout << endl;
    for (int i = 0; i < Siuntos.size(); i++)
        cout << Siuntos[i].t << " ";
    cout << endl;
    cout << Siuntos[Siuntos.size() - 1].t - Siuntos[Siuntos.size() - 1].prT;
}
