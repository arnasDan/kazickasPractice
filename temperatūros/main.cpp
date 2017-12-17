#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int> > Tmp;
    ifstream in("U2.txt");
    int n, sum;
    in >> n;
    double maxAvg = 0;
    int beg = 0, curBeg = 0;
    int maxL = 0, l = 0;
    Tmp.resize(n);
    for (int i = 0; i < n; i++)
    {
        Tmp[i].resize(30);
        for (int j = 0; j < 30; j++)
            in >> Tmp[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (Tmp[i][j] >= 0)
            {
                sum += Tmp[i][j];
                l++;
            }
            if (Tmp[i][j] < 0 || j + 1 == 30)
            {
                if (((double) sum / l) > maxAvg)
                {
                    maxAvg = (double) sum/l;
                    maxL = l + curBeg;
                    beg = curBeg;
                }
                curBeg = j + 1;
                l = 0;
                sum = 0;
            }

        }
        for (int j = beg; j < maxL; j++)
            cout << Tmp[i][j] << " ";
        cout << endl;
    }
    return 0;
}
