#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> lp(n + 1, 0), pr;
    for (int i = 2; i < (int)lp.size(); ++i)
    {
        if (lp[i] == 0)
        {
            pr.push_back(i);
            lp[i] = i;
        }
    for (int j = 0; j < (int)pr.size(); j++)
        if (i * pr[j] <= n && pr[j] <= lp[i])
            lp[i * pr[j]] = pr[j];
    }


    for (int i : pr)
        cout << i << " ";

    return 0;
}
