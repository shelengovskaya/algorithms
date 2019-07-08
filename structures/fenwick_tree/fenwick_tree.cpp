#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> t;

void add(int pos, int diff)    //���������� �������� � ������ �������
{
    while (pos <= n)
    {
        t[pos] += diff;
        pos |= (pos + 1);
    }
}

int sum(int pos)	//������� �����
{
    int s = 0;
    while (pos >= 0)
    {
        s += t[pos];
        pos = (pos &(pos + 1)) - 1;
    }
    return s;
}

int main()
{
    cin >> n;   //���-�� ���������
    t.assign(n * 4, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;   //������ ���������
        add(i, x);  //���������� ��������� � ������ �������
    }
    int k;  //���-�� �������� �� ���������� �����
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;   //������ ����� � ����� ������ ��� �������� ����� �� ������� [l, r]
        cin >> l >> r;
        l--; r--;
        cout << sum(r) - sum(l - 1) << endl;    //����� ����� �� ������� [l, r]
    }
    return 0;
}
