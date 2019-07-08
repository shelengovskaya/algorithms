#include <bits/stdc++.h>


using namespace std;

vector <int> a[10];
vector <int> ans;
vector <bool> used;

void dfs(int v)
{
    used[v] = true;
    for (int i : a[v])
    {
        if (!used[i])
            dfs(i);
    }
    ans.push_back(v);
}



int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    reverse (ans.begin(), ans.end());
    for (int i : ans)
        cout << ++i << ", ";
    return 0;
}
