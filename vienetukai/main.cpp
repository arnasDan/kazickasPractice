#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void convertToBinary(int n, string &binary);
void skaityti(vector <int> &Num);
int zero(string bi);

int main()
{
    string binary = "";
    vector <int> Num;
    convertToBinary(7, binary);
    cout << binary << endl;
    return 0;
}

void skaityti(vector <int> &Num)
{
    int n;
    ifstream in("U1.txt");
    in >> n;
    Num.resize(n);
    for (int i = 0; i < n; i++)
        in >> Num[i];
}

void dalykai(vector <int> Num)
{
    string tmp;
    for (int i = 0; i < Num.size(); i++)
    {
        for (int j = 0;)
        tmp = "";
        convertToBinary(Num[i], tmp);

    }
}

int zero(string bi)
{
    int c = 0;
    for (int i = 0; i < bi.size(); i++)
        if (bi[i] == '1')
            c++;

}

void convertToBinary(int n, string &binary)
{
    if (n / 2 != 0)
        convertToBinary(n / 2, binary);
    binary += n % 2 + 48;
}
