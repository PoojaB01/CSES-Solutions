// https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;
    cin >> n;
    while (1)
    {
        cout << n << ' ';
        if (n == 1)
        {
            cout << endl;
            return 0;
        }
        n = n % 2 ? n * 3 + 1 : n / 2;
    }
    return 0;
}