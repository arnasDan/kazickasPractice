#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct xy
{
    double x;
    double y;
};

void skaityti(vector <xy> &Sol, xy &ziog, xy &varle, double &vMax, double &vPag);
void suoliai(vector <xy> Sol, xy ziog, xy varle, double vMax, double vPag);

int main()
{
    vector <xy> Sol;
    xy ziog;
    xy varle;
    double vMax, vPag;
    skaityti(Sol, ziog, varle, vMax, vPag);
    suoliai(Sol, ziog, varle, vMax, vPag);
    return 0;
}

void skaityti(vector <xy> &Sol, xy &ziog, xy &varle, double &vMax, double &vPag)
{
    int n;
    ifstream in("U1.txt");
    in >> varle.x >> varle.y >> vMax >> vPag;
    in >> ziog.x >> ziog.y;
    in >> n;
    Sol.resize(n);
    for (int i = 0; i < n; i++)
        in >> Sol[i].x >> Sol[i].y;
}

void suoliai(vector <xy> Sol, xy ziog, xy varle, double vMax, double vPag)
{
    int n = 0;
    xy ziogPr = ziog;
    xy varlePr = varle;
    xy suol;
    double s;
    double koe;
    for (int i = 0; i < Sol.size(); i++)
    {
        s = sqrt((varle.x - ziog.x) * (varle.x - ziog.x) + (varle.y - ziog.y) * (varle.y - ziog.y));
        koe = vMax / s;
        //cout << koe << " " << s << endl;
        suol.x = abs(varle.x - ziog.x) * koe;
        suol.y = abs(varle.y - ziog.y) * koe;
        //cout << suol.x << " " << suol.y << endl;
        if (varle.y > ziog.y)
            varle.y -= suol.y;
        else
            varle.y += suol.y;
        if (varle.x > ziog.x)
            varle.x -= suol.x;
        else
            varle.x += suol.x;
        ziog.x += Sol[i].x;
        ziog.y += Sol[i].y;
        s = sqrt((varle.x - ziog.x) * (varle.x - ziog.x) + (varle.y - ziog.y) * (varle.y - ziog.y));
        //cout << "z: " << ziog.x << " " << ziog.y << "   v: " << varle.x << " " << varle.y << endl;
        //cout << s << endl;
        if (s <= vPag)
        {
            cout << "1" << endl;
            n++;
            ziog = ziogPr;
            varle = varlePr;
        }
        else
            cout << "0" << endl;
    }
    cout << n << endl;
}
