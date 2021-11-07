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
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long double ESP = 1e-8;
vector<vector<int>> gp;
vector<int> vst;
int sol=0;
bool dfs(int ro){
    vst[ro]=1;
    for(auto i :gp[ro]){
        if(!vst[i])
            dfs(i);
    }
    return true;
}
int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout)
    int n,m;
    cin>>n>>m;
    gp=vector<vector<int>> (n+2,vector<int>(n+2,0));
    vst.resize(n+2);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u,--v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    dfs(0);
    bool s=1;
    for(int i=0;i<n;i++){
        if(!vst[i])
        s=0;
    }
    if(n==m+1&&s){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

}
