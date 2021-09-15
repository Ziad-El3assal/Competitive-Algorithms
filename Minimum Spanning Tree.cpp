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
const int M=1e5+6,N=1e5+5;
int n,m,w;
pair<int,pair<int,int>> edges[M];
int par[N],siz[N];
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
        if(siz[a]>siz[b])
        {
            swap(a,b);
        }
        par[b]=a;
        siz[b]+=siz[a];
    }
}
lld kruskal()
{
    lld ret=0;
    iota(par,par+n+1,0);
    sort(edges,edges+m);
    for(int i=0; i<m; i++)
    {

        if(findpar(edges[i].from)!=findpar(edges[i].to))
        {
            join(edges[i].from,edges[i].to);
            ret+=edges[i].cost;
        }
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    memset(siz,1,n*sizeof(siz[0]));
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]= {w,{u,v}};
    }
    cout<<kruskal();

}
