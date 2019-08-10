#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector < vector <int> > a(n, vector <int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    // проверить, есть ли ребра нечетной степени(может быть только 2), добавить между ними ребро, после удалить
    stack <int> st;
    st.push(0);
    vector <bool> p(n, true);
    vector <int> res;
    p[0] = false;
    while (!st.empty())
    {
        int j = 0;
        int i = st.top();
        while (a[i][j] == 0 && j < a[i].size()) j++;
        if (a[i][j] == 1)
        {
            st.push(j);
            p[j] = false;
            a[i][j] = a[j][i] = 0;
        }
        else
        {
            res.push_back(st.top() + 1);
            st.pop();
        }
    }
    for (int i = 0; i < n; i++)
        if (p[i])
        {
            cout << "-1";
            return 0;
        }
    for (int i : res)
        cout << i << " ";
    return 0;
}
