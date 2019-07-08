#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[4][4] = {
    {0, 5, 9, 100},
    {100, 0, 2, 8},
    {100, 100, 0, 7},
    {4, 100, 100, 0,},
    };
    for (int k = 0; k < 4; k++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
