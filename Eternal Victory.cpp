#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
void run()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef Local
    freopen("input.txt", "r", stdin);
#else
#endif
}
#define sz(x) x.size();
const int N=1e5+5;
vector<vector<pair<lld,lld>>> gp;
lld n,sum=0,mx=-1;
vector<bool>vis;
pair<lld,lld> dfs(int n)
{
    vis[n]=1;
    lld sum=0,mx=0;
    for(pair<lld,lld> v:gp[n])
    {
        int d=v.first;
        int y=v.second;
        if(vis[d])continue;
        pair<lld,lld> child=dfs(d);
        sum+=child.first+y;
        mx=max(child.second+y,mx);
    }
    return {sum,mx};
}
int main()
{
    cin>>n;
    gp.clear();
    gp.resize(n);
    vis=vector<bool>(n,0);
    for(int i=0; i<n-1; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        gp[--u].push_back({--v,c});
        gp[v].push_back({u,c});

    }
    pair<lld,lld> ans=dfs(0);
   // cout<<ans.first<<" "<<ans.second<<'\n';
    cout<<2*ans.first-ans.second;
}



