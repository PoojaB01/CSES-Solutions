// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    long n, x;

    cin >> n;
    long sum = n * (n + 1);
    sum /= 2;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        sum -= x;
    }
    
    cout << sum << endl;
    return 0;
}