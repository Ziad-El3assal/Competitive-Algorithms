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
vector<int>par,par1,sz;
int findparent(int u,vector<int>&par)
{
    if(par[u]==u)return u;
    return par[u]=findparent(par[u],par);
}
void join(int a,int b,vector<int>&par)
{

    a=findparent(a,par);
    b=findparent(b,par);
    if(a!=b)
    {
        par[b]=a;
    }
}
int main()
{
    run();
    int n,m,m1;
    cin>>n>>m>>m1;
    par.resize(n);
    iota(par.begin(),par.end(),0);
    par1.resize(n);
    iota(par1.begin(),par1.end(),0);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        join(u,v,par);
    }
    for(int i=0; i<m1; i++)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        join(u,v,par1);
    }
    vector<pair<int,int>> ans;
    for(int i=0; i<n ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
                if(findparent(i,par1)!=findparent(j,par1)&&findparent(i,par)!=findparent(j,par)){
                    ans.pb({i,j});
                    join(i,j,par);
                    join(i,j,par1);
                }
        }

    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<++x.first<<" "<<++x.second<<endl;
    }
}
