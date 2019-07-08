#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> t;

void add(int pos, int diff)    //добавление элемента в дерево Фенвика
{
    while (pos <= n)
    {
        t[pos] += diff;
        pos |= (pos + 1);
    }
}

int sum(int pos)	//подсчет суммы
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
    cin >> n;   //кол-во элементов
    t.assign(n * 4, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;   //чтение элементов
        add(i, x);  //добавление элементов в массив Фенвика
    }
    int k;  //кол-во запросов на нахождение суммы
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;   //чтение левой и првой границ для находния суммы на отрезке [l, r]
        cin >> l >> r;
        l--; r--;
        cout << sum(r) - sum(l - 1) << endl;    //вывод суммы на отрезке [l, r]
    }
    return 0;
}
