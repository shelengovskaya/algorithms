#include <iostream>

using namespace std;

int binpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return binpow(a, n / 2) * binpow(a, n / 2);
    else
        return binpow(a, n - 1) * a;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << binpow(a, n);
    return 0;
}
