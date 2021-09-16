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
#define cost first
#define from second.first
#define to  second.second
#define pb push_back
const int M=1e5+6,N=1e5+5;
int n,m,w;
vector<pair<int,pair<int,int>>> edges;
vector<int>par,sz;
int findpar(int u)
{
    if(u==par[u]) return u;
    return par[u]=findpar(par[u]);
}
void join(int a,int b)
{
    a=findpar(a);
    b=findpar(b);
    if(a!=b)
    {
        //to make sure that the smaller component is connected to larger one not the X
        if(sz[a]>sz[b])
        {
            swap(a,b);
        }
        par[b]=a;
        sz[b]+=sz[a];
    }
}
lld kruskal()
{
    lld ret=0;
    sort(edges.begin(),edges.end());
    iota(par.begin(),par.end(),0);
    for(auto xp:edges)
    {
        if(findpar(xp.from)!=findpar(xp.to))
        {
            ret+=xp.cost;
            join(xp.from,xp.to);

        }
    }
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        par.clear();
        par.resize(n);
        edges.clear();
        sz=vector<int>(n,0);
        for(int i=0; i<n; i++)
        {
            string x;
            cin>>x;
            int c;
            cin>>c;
            while(c--)
            {
                int u,v;
                cin>>u>>v;
                --u;
                edges.pb({v,{i,u}});
            }
        }
        cout<<kruskal()<<endl;
    }


}
