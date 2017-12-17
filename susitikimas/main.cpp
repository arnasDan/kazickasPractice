#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

struct xy
{
    int x, y;
};

void skaityti(vector <xy> &Drg, vector <xy> &Sus, vector <xy> &Pic, xy &size, bool map[11][11]);
void search(xy target, bool map[11][11], int len[11][11], xy cur, xy size, int prev, int &lenToReturn);
void lenReset(int len[11][11], xy size);
void isvesti(xy sus, xy pic, vector <xy> Drg, xy size, int len, bool noPath);

int main()
{
    int leng, lenSum, lenMin = INT_MAX, minNr, minPicNr, lenMinSus;
    bool noPath = false;
    vector <xy> Drg;
    vector <xy> Sus;
    vector <xy> Pic;
    xy size;
    bool map[11][11];
    int len[11][11];
    skaityti(Drg, Sus, Pic, size, map);
    for (int i = 0; i < Sus.size(); i++)
    {
        lenSum = 0;
        for (int j = 0; j < Drg.size(); j++)
        {
            leng = INT_MAX;
            lenReset(len, size);
            search(Sus[i], map, len, Drg[j], size, 0, leng);
            if (leng != INT_MAX)
                lenSum += leng;
            else
            {
                lenSum = 0;
                break;
            }
        }
        if (lenSum < lenMin)
        {
            lenMin = lenSum;
            minNr = i;
        }
    }
    if (lenSum == 0)
        noPath = true;
    else
    {
        lenMinSus = lenMin;
        lenMin = INT_MAX;
        for (int i = 0; i < Pic.size(); i++)
        {
            leng = INT_MAX;
            lenReset(len, size);
            search(Pic[i], map, len, Sus[minNr], size, 0, leng);
            if (leng < lenMin)
            {
                lenMin = leng;
                minPicNr = i;
            }
        }
    }
    if (lenMin == INT_MAX)
        noPath = true;
    isvesti(Sus[minNr], Pic[minPicNr], Drg, size, (lenMin + lenMinSus) * 2, noPath);
    return 0;
}

void skaityti(vector <xy> &Drg, vector <xy> &Sus, vector <xy> &Pic, xy &size, bool map[11][11])
{
    char read;
    ifstream in("U3.txt");
    in >> size.x >> size.y;
    for (int i = 0; i < size.x; i++)
        for (int j = 0; j < size.y; j++)
        {
            in >> read;
            if (read == '.' || read == 'S' || read == 'D')
                map[i][j] = 1;
            else
                map[i][j] = 0;
            if (read == 'S')
                Sus.push_back(xy{i, j});
            if (read == 'D')
                Drg.push_back(xy{i, j});
            if (read == 'P')
                Pic.push_back(xy{i, j});
        }
}

void isvesti(xy sus, xy pic, vector <xy> Drg, xy size, int len, bool noPath)
{
    for (int i = 0; i < Drg.size(); i++)
        cout << Drg[i].y + 1 << " " << size.x - Drg[i].x << endl;
    if (!noPath)
    {
        cout << "Susitikimo vieta " << sus.y + 1 << " " << size.x - sus.x << endl;
        cout << "Picerija " << pic.y + 1 << " " << size.x - pic.x<< endl;
        cout << "Nueita " << len << endl;
    }
    else
        cout << "Neimanoma" << endl;
}

void lenReset(int len[11][11], xy size)
{
    for (int i = 0; i < size.x; i++)
        for (int j = 0; j < size.y; j++)
            len[i][j] = INT_MAX;
}

void search(xy target, bool map[11][11], int len[11][11], xy cur, xy size, int prev, int &lenToReturn)
{
    len[cur.x][cur.y] = prev + 1;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 && j != 0)
                continue;
            if (i == 0 && j == 0)
                continue;
            if (cur.x + i < 0 || cur.y + j < 0 || cur.x + i >= size.x || cur.y + j >= size.y)
                continue;
            if (cur.x + i == target.x && cur.y + j == target.y && len[cur.x][cur.y] < lenToReturn)
                lenToReturn = len[cur.x][cur.y] + 1;
            else if (map[cur.x + i][cur.y + j] && len[cur.x + i][cur.y + j] > (len[cur.x][cur.y] + 1))
                search(target, map, len, xy{cur.x + i, cur.y + j}, size, len[cur.x][cur.y], lenToReturn);
        }
}
