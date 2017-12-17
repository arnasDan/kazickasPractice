#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct deze
{
    vector <int> Mat;
    int s;
    int suSienom(int n)
    {
        return Mat[n] - s;
    }
};

struct ko
{
    vector <deze> Dez;
};

void skaityti(vector <ko> &Kompl);
bool sortas(deze a, deze b);

int main()
{
    vector <ko> Kompl;
    skaityti(Kompl);
    for (int i = 0; i < Kompl.size(); i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cout << Kompl[i].Dez[j].Mat[k] << " ";
    return 0;
}

void skaityti(vector <ko> &Kompl)
{
    int n, s;
    ifstream in("U1.txt");
    in >> n >> s;
    Kompl.resize(n / 3);
    for (int i = 0; i < n / 3; i++)
    {
        Kompl[i].Dez.resize(3);
        for (int j = 0; j < 3; j++)
        {
            Kompl[i].Dez[j].s = s;
            Kompl[i].Dez[j].Mat.resize(3);
            for (int k = 0; k < 3; k++)
                in >> Kompl[i].Dez[j].Mat[k];
            sort(Kompl[i].Dez[j].Mat.begin(), Kompl[i].Dez[j].Mat.end());
            //sort(Kompl[i].Dez.begin(), Kompl[i].Dez.end(), sortas); wtf
        }
    }
}

bool sortas(deze a, deze b)
{
    return (a.Mat[0] < b.Mat[0]);
}
