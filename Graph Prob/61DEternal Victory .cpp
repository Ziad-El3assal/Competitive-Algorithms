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
#define pll pair<ll,ll>
#define vvpll vector<vector<pair<ll,ll>>>
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long double ESP = 1e-8;
vvpll gp;
vector<int> vst;
ll sum=0,mx=0;
pair<ll,ll> dfs(int node){
    vst[node]=1;
    ll sum=0,mx=0;
    for(auto v:gp[node]){
        int c=v.first;
        int b=v.second;
        if(vst[c])continue;
        pair<ll,ll> sol=dfs(c);
        sum+=sol.first+b;
        mx=max(mx,sol.second+b);
        
    }
    return {sum,mx};
}
int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout)
    int n;cin>>n;
    gp.resize(n+2);
    vst.resize(n+2);
    for(int i=0;i<n-1;i++){
        int u,v,c;
        cin>>u>>v>>c;
        --u,--v;
        gp[u].pb({v,c});
        gp[v].pb({u,c});
    }
    pll sol=dfs(0);
    cout<<2*sol.first-sol.second<<endl;

}
