#include <iostream>

using namespace std;

int p[2][2];

void mxm(int& p, int n)
{
    if (n == 0)
    {
        p[0][0] = 0;
        p[0][1] = 1;
        p[1][0] = 1;
        p[1][1] = 1;
    }
    else
    if (n % 2 == 0)
        return mxm(p, n / 2);
    else
        return
    {
        p[0][0] = p[0][0] * p[0][0] + p[0][1]*p[1][0];
        p[0][1] = p[0][0] * p[0][1] + p[0][1]*p[1][1];
        p[1][0] = p[1][0] * p[0][0] + p[1][1]*p[1][0];
        p[1][1] = p[1][0] * p[0][1] + p[1][1]*p[1][1];
    }
}

int fibonacci(int n)
{
    if (n % 2 == 0)
        return intxm(1, mxm(p, n));
    else
        return intxm(0, mxm(p, n));
}


int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
