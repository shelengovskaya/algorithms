#include <iostream>

using namespace std;

int a, b, c, n;

void print(int from, int to)
{
    cout << "From " << from << ", to " << to << endl;
}

void carry(int a, int b, int c, int n)
{
    if (n > 0)
    {
        carry(a, c, b, n - 1);
        print (a, c);
        carry(b, a, c, n - 1);
    }
}


int main()
{
    cin >> n;
    a = 1;
    b = 2;
    c = 3;
    carry(a, b, c, n);
    cout << a << " " << b << " " << c << endl;
    return 0;
}
