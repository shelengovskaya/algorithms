#include <bits/stdc++.h>

using namespace std;

/*bool comp (pair < int, pair <int, int> > a, pair < int, pair <int, int> > b)
{
    return a.first < b.first;
}*/

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector < pair < int, pair <int, int> > > g;
    vector < pair <int, int> > res;
    vector <int> p(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back(make_pair(c, make_pair(--a, --b)));
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int c = g[i].first;
        int a = g[i].second.first;
        int b = g[i].second.second;
        if (p[a] != p[b])
        {
            ans += c;
            res.push_back(make_pair(a + 1, b + 1));
            int old_num = p[b];
            int new_num = p[a];
            for (int j = 0; j < n; j++)
                if (p[j] == old_num)
                    p[j] = new_num;
        }
    }
    for (pair <int, int> i : res)
        cout << i.first << " " << i.second << endl;
    cout << ans;
    return 0;
}
