// https://cses.fi/problemset/task/1132/

#include<bits/stdc++.h>
 
using namespace std;
 
#define lli long long

int calc_dist(int x, vector<int> v[], vector<int> &vi, vector<int> &dist, int k)
{
    vi[x] = 0;
    int t = k;

    for(int i=0;i<(int)v[x].size();i++)
    {
        if(vi[v[x][i]])
        {
            t = max(calc_dist(v[x][i], v, vi, dist, k+1), t);
        }
    }

    dist[x] = t - k;

    return t;
}
 
void calc_maxdist(int x, vector<int> v[], vector<int> &vi, vector<int> &dist, vector<int> &ans, int k)
{
    vi[x] = 0;
    int m1 = -1, m2 = -1;

    for(int i=0;i<(int)v[x].size();i++)
    {
        if(vi[v[x][i]])
        {
            if(m1 == -1)
            {
                m1 = v[x][i];
            }
            else if(dist[m1]<dist[v[x][i]])
            {
                m2 = m1;
                m1 = v[x][i];
            }
            else if(m2 == -1)
            {
                m2 = v[x][i];
            }
            else if(dist[m2]<dist[v[x][i]])
            {
                m2 = v[x][i];
            }
        }
    }

    if(m1 == -1)
    {
        ans[x] = k;
    }
    else ans[x] = max(dist[m1] + 1, k);

    for(int i=0;i<(int)v[x].size();i++)
    {
        if(vi[v[x][i]])
        {
            if(v[x][i] == m1)
            {
                if(m2 == -1)
                {
                    calc_maxdist(v[x][i], v, vi, dist, ans, k+1);
                }
                else {
                    calc_maxdist(v[x][i], v, vi, dist, ans, max(k+1, dist[m2] + 2));
                }
            }
            else {
                calc_maxdist(v[x][i], v, vi, dist, ans, max(dist[m1] + 2, k+1));
            }
        }
    }
}
 
 
void solve()
{ 
    int n;
    cin>>n;
    int x, y;
    vector<int> v[n];

    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }

    vector<int> vi(n, 1);
    vector<int> dist(n, 0);

    calc_dist(0, v, vi, dist, 0);

    vi.assign(n, 1);
    vector<int> ans(n, 0);

    calc_maxdist(0, v, vi, dist, ans, 0);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}