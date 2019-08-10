#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (int i = 2; i*i <= n; i++)
        if (p[i])
            if (i * 1ll * i <= n)
                for (int j = i*i; j <= n; j += i)
                    p[j] = false;
    for (int i = 0; i <= n; i++)
    if (p[i])
        cout << i << " ";
    return 0;
}
