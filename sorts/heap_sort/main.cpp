#include <bits/stdc++.h>

using namespace std;

vector <int> a;

void siftup(int i)
{
    while (a[i] > a[(i - 1) / 2])
    {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftdown(int i)
{
    while (i * 2 + 1 < a.size())
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int j = left;
        if (right < a.size() && a[right] > a[left])
            j = right;
        if (a[i] >= a[j])
            break;
        swap(a[i], a[j]);
        i = j;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector <int> res;
    for (int i = 0; i < n; i++)
    {
        int diff;
        cin >> diff;
        a.push_back(diff);
    }
    for (int i = n - 1; i > -1; i--)
    {
        siftdown(i);
    }
    for (int i = 0; i < n; i++)
    {
/*        for (int i : a)
            cout << i << " ";
        cout << endl;*/
        res.push_back(a[0]);
        a[0] = a[a.size() - 1];
        a.pop_back();
        siftdown(0);

    }
    reverse(res.begin(), res.end());
    for (int i : res)
            cout << i << " ";
    return 0;
}
