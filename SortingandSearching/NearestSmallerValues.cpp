// https://cses.fi/problemset/task/1645/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n;
    cin >> n;
    stack<pair<int, int>> s;
    s.push({INT_MIN, 0});
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        while (!s.empty())
        {
            if (s.top().first >= a)
            {
                s.pop();
            }
            else
                break;
        }
        cout << s.top().second << ' ';
        s.push({a, i + 1});
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}