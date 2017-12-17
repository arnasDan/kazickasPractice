#include <iostream>
#include <fstream>

using namespace std;

struct koord
{
    int x, y;
};

struct rinkinys
{
    koord robo1;
    koord robo2;
    string kom;
};

void skaityti(rinkinys Rink[]);
void judeti(rinkinys Rink[]);

int main()
{
    rinkinys Rink[3];
    skaityti(Rink);
    judeti(Rink);
    return 0;
}

void skaityti(rinkinys Rink[])
{
    ifstream in("U1.txt");
    for (int i = 0; i < 3; i++)
    {
        in >> Rink[i].robo1.x >> Rink[i].robo1.y >> Rink[i].robo2.x >> Rink[i].robo2.y;
        in.ignore(128, '\n');
        in >> Rink[i].kom;
    }
}

void judeti(rinkinys Rink[])
{
    bool avarija;
    for (int i = 0; i < 3; i++)
    {
        avarija = false;
        for (int j = 0; j < Rink[i].kom.size(); j++)
        {
            if ((j + 1) % 2 != 0)
            {
                if (Rink[i].kom[j] == 'K')
                    Rink[i].robo1.y++;
                if (Rink[i].kom[j] == 'A')
                    Rink[i].robo1.x--;
                if (Rink[i].kom[j] == 'P')
                    Rink[i].robo1.x++;
                if (Rink[i].kom[j] == 'D')
                    Rink[i].robo1.y--;
            }
            else
            {
                if (Rink[i].kom[j] == 'K')
                    Rink[i].robo2.y++;
                if (Rink[i].kom[j] == 'A')
                    Rink[i].robo2.x--;
                if (Rink[i].kom[j] == 'P')
                    Rink[i].robo2.x++;
                if (Rink[i].kom[j] == 'D')
                    Rink[i].robo2.y--;
                if (Rink[i].robo1.x == Rink[i].robo2.x && Rink[i].robo1.y == Rink[i].robo2.y)
                    avarija = true;
            }
        }
        cout << Rink[i].robo1.x << " " << Rink[i].robo1.y << " " << Rink[i].robo2.x << " " << Rink[i].robo2.y;
        if (avarija)
            cout << " AVARIJA";
        cout << endl;
    }
}
