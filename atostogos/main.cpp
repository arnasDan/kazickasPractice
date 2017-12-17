#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void skaityti(int &d, vector <vector <bool > > &Laikai);
void tikrinti(vector <bool> &Atostogos, int d, vector <vector <bool > > Laikai);

int main()
{
    int d;
    vector <vector <bool> > Laikai;
    vector <bool> Atostogos;
    skaityti(d, Laikai);
    tikrinti(Atostogos, d, Laikai);
    return 0;
}

void skaityti(int &d, vector <vector <bool > > &Laikai)
{
    int drg, n, tmp;
    ifstream in("U3.txt");
    in >> d >> drg >> n;
    Laikai.resize(drg);
    for (int i = 0; i < drg; i++)
    {
        Laikai[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            in >> tmp;
            Laikai[i][j] = tmp;
        }
    }
}

void tikrinti(vector <bool> &Atostogos, int d, vector <vector <bool > > Laikai)
{
    int maxD = Laikai.size(), curD;
    bool g;
    while (maxD != curD)
    {
        for (int i = d - 1; i < Laikai[0].size(); i++)
        {
            curD = 0;
            for (int j = 0; j < Laikai.size(); j++)
            {
                g = true;
                for (int k = 0; k < d; k++)
                {
                    if (Laikai[j][i - k])
                    {
                        g = false;
                        break;
                    }
                }
                if (g)
                    curD++;
            }
            if (curD == maxD)
            {
                cout << i << " " << maxD;
                return;
            }
        }
        maxD--;
        curD = 0;
    }
}
