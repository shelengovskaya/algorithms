#include <bits/stdc++.h>

using namespace std;

vector <int> a = {5, 3, 2, 8, 10, 11, 1, 6, 8};

void quicksort(int first, int last)
{
    int l = first;
    int r = last;
    int mid = a[(l + r) / 2];
    do
    {
        while (a[l] < mid) l++;
        while (a[r] > mid) r--;
        if (l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }while (l < r);
    if (first < r) quicksort(first, r);
    if (l < last) quicksort(l, last);
}

template <typename Collection>
string Join(const Collection& a, string d)
{
    stringstream ss;
    bool first = true;
    for (auto i : a)
    {
        if (!first)
            ss << d;
        first = false;
        ss << i;
    }
    return ss.str();
}

int main()
{
    cout << "{" << Join(a, ", ") << "}" << endl;
	sort(a.begin(), a.end());
    cout << "{" << Join(a, ", ") << "}";

    return 0;
}
