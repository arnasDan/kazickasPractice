#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tsk
{
    int X[2];
    int Y[2];
};

void skaityti(int map[102][102], vector <tsk> &Eil);
void search(int map[102][102], int visited[102][102], int &l, int &s, int x, int y);
void isvesti(int maxL, int s, vector <tsk> Eil);

int main()
{
    vector <tsk> Eil;
    int maxL = 0, l = 0, s = 0;
    int map[102][102] = {0};
    int visited[102][102] = {0};
    skaityti(map, Eil);
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
            if (map[i][j] == 1 && !visited[i][j])
            {
                search(map, visited, l, s, i, j);
                if (l > maxL)
                    maxL = l;
                l = 0;
            }
    isvesti(maxL, s, Eil);
    return 0;
}

void search(int map[102][102], int visited[102][102], int &l, int &s, int x, int y)
{
    visited[x][y] = 1;
    s++;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (x + i < 0 || y + j < 0 || x + i >= 102 || y + j >= 102)
                continue;
            if ((i != 0 && j != 0) || (i == 0 && j == 0))
                continue;
            if (map[x + i][y + j] == 0)
                l++;
            if (map[x + i][y + j] == 1 && !visited[x + i][y + j])
                search(map, visited, l, s, x + i, y + j);
        }
}

void skaityti(int map[102][102], vector <tsk> &Eil)
{
    int n;
    ifstream in("U3.txt");
    in >> n;
    Eil.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            in >> Eil[i].X[j] >> Eil[i].Y[j];
            Eil[i].X[j] += 50;
            Eil[i].Y[j] += 50;
        }
        for (int j = Eil[i].X[0]; j < Eil[i].X[1]; j++)
            for (int k = Eil[i].Y[0]; k < Eil[i].Y[1]; k++)
                map[k][j] = true;
    }
}

void isvesti(int maxL, int s, vector <tsk> Eil)
{
    for (int i = 0; i < Eil.size(); i++)
    {
        for (int j = 0; j < 2; j++)
            cout << Eil[i].X[j] - 50 << " " << Eil[i].Y[j] - 50 << " ";
        cout << endl;
    }
    cout << "Bendras plotas " << s << endl;
    cout << "Ilgiausios perimetro linijos ilgis " << maxL << endl;
}
