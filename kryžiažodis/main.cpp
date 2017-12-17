#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct xy
{
    int x, y;
};

struct zodis
{
    string txt;
    xy pr;
    vector <xy> Kelias;
};

void skaityti(vector <zodis> &Zod, char map[102][102], xy &size);
void ieskoti(int n, zodis &zod, char map[102][102], vector <xy> Kelias, xy size, xy cur);
void writeToNum(zodis zod, int nr, int num[102][102]);

int main()
{
    char map[102][102];
    int num[102][102];
    xy size;
    vector <zodis> Zod;
    vector <xy> Kelias;
    skaityti(Zod, map, size);
    for (int i = 0; i < Zod.size(); i++)
    {
        ieskoti(0, Zod[i], map, Kelias, size, Zod[i].pr);
        writeToNum(Zod[i], i + 1, num);
    }
    for (int i = 0; i < size.x; i++)
    {
        for (int j = 0; j < size.y; j++)
            cout << setw(size.x) << num[i][j] << ' ';
        cout << endl;
    }
    int sum;
    for (int i = 0; i < size.y; i++)
    {
        sum = 0;
        for (int j = 0; j < size.x; j++)
            sum += num[j][i];
        cout << setw(size.x) << sum << " ";
    }
    return 0;
}

void writeToNum(zodis zod, int nr, int num[102][102])
{
    for (int i = 0; i < zod.Kelias.size(); i++)
        num[zod.Kelias[i].x][zod.Kelias[i].y] = nr;
}

void ieskoti(int n, zodis &zod, char map[102][102], vector <xy> Kelias, xy size, xy cur)
{
    Kelias.push_back(cur);
    n++;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if ((i != 0 && j != 0) || (i == 0 && j == 0))
                continue;
            //cout << cur.x << " " << cur.y << " " << cur.x + i << " " << cur.y + j << " " << zod.txt << " " << map[cur.x + i][cur.y + j] << zod.txt[n] << endl;
            if (cur.x + i < 0 || cur.y + j < 0 || cur.x + i == size.x || cur.y + j == size.y)
                continue;
            if (n == zod.txt.size() - 1 && map[cur.x + i][cur.y + j] == zod.txt[n])
            {
                Kelias.push_back(xy{cur.x + i, cur.y + j});
                zod.Kelias = Kelias;
                return;
            }
            else if (map[cur.x + i][cur.y + j] == zod.txt[n])
            {
                ieskoti(n, zod, map, Kelias, size, xy{cur.x + i, cur.y + j});
            }
        }
}

void skaityti(vector <zodis> &Zod, char map[102][102], xy &size)
{
    int k;
    ifstream in("U3.txt");
    in >> size.x >> size.y;
    for (int i = 0; i < size.x; i++)
        for (int j = 0; j < size.y; j++)
            in >> map[i][j];
    in >> k;
    Zod.resize(k);
    for (int i = 0; i < k; i++)
    {
        in >> Zod[i].txt >> Zod[i].pr.x >> Zod[i].pr.y;
        Zod[i].pr.x--;
        Zod[i].pr.y--;
    }

}
