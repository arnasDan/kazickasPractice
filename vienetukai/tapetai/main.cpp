#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct tapetas
{
    double kaina;
    int x;
    int y;
    string pav;
};

struct sandelys
{
    int x;
    int y;
    vector <tapetas> Tap;
};

void skaityti(vector <sandelys> &Sand);
void rastiKainas(vector <sandelys> &Sand);
void isvesti(vector <sandelys> Sand);
string pigiausia(vector <tapetas> Tap);

int main()
{
    vector <sandelys> Sand;
    skaityti(Sand);
    rastiKainas(Sand);
    isvesti(Sand);
    return 0;
}

void skaityti(vector <sandelys> &Sand)
{
    int n, k;
    ifstream in("U1.txt");
    in >> n;
    Sand.resize(n);
    for (int i = 0; i < n; i++)
    {
        in >> Sand[i].x >> Sand[i].y >> k;
        Sand[i].Tap.resize(k);
        for (int j = 0; j < k; j++)
            in >> Sand[i].Tap[j].pav >> Sand[i].Tap[j].y >> Sand[i].Tap[j].x >> Sand[i].Tap[j].kaina;
    }
}

void rastiKainas(vector <sandelys> &Sand)
{
    for (int i = 0; i < Sand.size(); i++)
        for (int j = 0; j < Sand[i].Tap.size(); j++)
            Sand[i].Tap[j].kaina *= ceil((double) Sand[i].Tap[j].x / Sand[i].x);
}

string pigiausia(vector <tapetas> Tap)
{
    int miin = 0;
    for (int i = 1; i < Tap.size(); i++)
        if (Tap[i].kaina < Tap[miin].kaina)
            miin = i;
    return Tap[miin].pav;

}

void isvesti(vector <sandelys> Sand)
{
    for (int i = 0; i < Sand.size(); i++)
    {
        for (int j = 0; j < Sand[i].Tap.size(); j++)
            cout << Sand[i].Tap[j].pav << " " << fixed << setprecision(2) << Sand[i].Tap[j].kaina << endl;
        cout << "Pigiausi tapetai " << pigiausia(Sand[i].Tap) << endl;
    }

}
