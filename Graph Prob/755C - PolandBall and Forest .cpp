#include <bits/stdc++.h>
//#include "Trie.h"
using namespace std;
typedef long long int ll;
typedef double ld;
#define pb push_back
#define sbe(x) sort(x.rbegin(), x.rend())
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//#define q int t;cin>>t; while(t--)
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvpll vector<vector<pair<ll, ll>>>
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long double ESP = 1e-8;
vector<vector<int>> gp;
vector<int> vis;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : gp[u])
    {
        if (!vis[v])
            dfs(v);
    }
}
int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout)
        int n;
    cin >> n;
    gp.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        gp[i].pb(x);
        gp[x].pb(i);
    }
    ll sol=0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        else{
            sol++;dfs(i);
        }
    }
    cout<<sol<<endl;
}
