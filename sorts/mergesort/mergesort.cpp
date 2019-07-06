#include <bits/stdc++.h>

using namespace std;

int a[10] = {1, 4, 2, 11, 7, 2, 5, 10, 9, 5};
int b[10];

void merge(int l, int r)
{
    int i = l;
    int mid = (l + r) / 2;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= r)
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}


void merge_sort (int l, int r)
{
    if (l < r)
        if (l + 1 == r)
        {
            if (a[l] > a[r])
                swap(a[l], a[r]);
        }
        else
        {
            int mid = (l + r) / 2;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            merge(l, r);
        }
}


int main()
{
    merge_sort(0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    return 0;
}
