#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}


int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
