#include <bits/stdc++.h>

using namespace std;


const int Inf = 30000;

int main()
{
    int n , s , f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector <vector <int> > a(n, vector <int> (n));
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector <int> d(n, Inf);
    d[s] = 0;
    priority_queue <pair <int, int > > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int len = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > d[v]) continue;
        for (int i = 0; i < n; i++) {
            int to = i;
            int length = a[v][i];
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push(make_pair(-d[to],to));
            }
        }
    }
    if (d[f] == Inf) cout << "False";
    else cout << d[f];
    return 0;
}
