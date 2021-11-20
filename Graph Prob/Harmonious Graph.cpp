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
vector<int>par,sz,mx,mn;
map<pair<int,int>,int>mp;
int findparent(int u)
{
    if(par[u]==u)return u;
    return par[u]=findparent(par[u]);
}
void join(int a,int b)
{
 
    a=findparent(a);
    b=findparent(b);
    if(a!=b)
    {
        if(mx[a]<mx[b])
            swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        mx[a]=max(mx[a],mx[b]);
    }
}
int main()
{
    run();
    int n,m;
    cin>>n>>m;
    par.resize(n);
    mx.resize(n);
    mn.resize(n);
    sz=vector<int>(n,1);
    iota(mx.begin(),mx.end(),0);
    iota(mn.begin(),mn.end(),0);
    iota(par.begin(),par.end(),0);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        join(u,v);
    }
    lld ans=0;
    for(int i=0;i<n;i++){
            for(int j=i;j<findparent(i);j++){
                if(findparent(i)!=findparent(j)){
                        ans++;
                        join(i,j);
                }
            }
            i=findparent(i);
    }
    cout<<ans;
}
