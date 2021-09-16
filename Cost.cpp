#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
void run()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
vector<pair<int,pair<int,int>>> gp;
vector<int>par,sz;
int findparent(int u){
    if(par[u]==u) return u;
    else return par[u]=findparent(par[u]);
}
lld cntpair;
lld MOD=1e9;
void join(int a,int b){
    a=findparent(a);
    b=findparent(b);
    if(a!=b){
        if(sz[a]>sz[b])
            swap(a,b);
        cntpair=(cntpair+ (lld)sz[a]*(lld)sz[b])%MOD;
        par[b]=a;
        sz[a]+=sz[b];
    }
}
int main()
{
    run();
    int n,m;cin>>n>>m;
    par.resize(n);
    sz.resize(n);
    iota(par.begin(),par.end(),0);
    sz=vector<int>(n,1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        --u,--v;
        gp.pb({c,{u,v}});
    }
    sbe(gp);
    lld ans=0;
    for(auto x:gp){
        join(x.second.first,x.second.second);
        ans=(ans+(x.first*cntpair)%MOD)%MOD;
    }
    cout<<ans<<endl;



}
