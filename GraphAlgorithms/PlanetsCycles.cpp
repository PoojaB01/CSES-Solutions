// https://cses.fi/problemset/task/1751

#include <bits/stdc++.h>

using namespace std;

#define lli long long

stack<int> s;
map<int, int> m;
int k = 0;

void calc(int x, vector<int> &dp, vector<int> &next)
{
    m[x] = k++;
    s.push(x);
    if (dp[next[x]] != -1)
    {
        while(!s.empty())
        {
            x = s.top();
            dp[x] = dp[next[x]] + 1;
            s.pop();
        }
        return;
    }
    if (m.find(next[x]) != m.end())
    {
        int c = k - m[next[x]];
        for (int i = 0; i < c; i++)
        {
            dp[s.top()] = c;
            s.pop();
        }
        while (!s.empty())
        {
            dp[s.top()] = ++c;
            s.pop();
        }
        m.clear();
        return;
    }
    calc(next[x], dp, next);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> next(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> next[i];
    }
    vector<int> dp(n + 1, -1);

    for (int i = 1; i < n + 1; i++)
    {
        if (dp[i] == -1)
        {
            calc(i, dp, next);
        }
        cout << dp[i] << ' ';
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