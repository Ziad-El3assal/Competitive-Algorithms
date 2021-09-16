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
int main()
{
    int n;
    cin>>n;
    string x,y;
    cin>>x>>y;
    par.resize(28);
    sz.resize(28);
    vector<pair<char,char>> c;
    iota(par.begin(),par.end(),0);
    int sol=0;
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]&&findpar(x[i]-'a')!=findpar(y[i]-'a')){
            join(x[i]-'a',y[i]-'a');
            sol++;
            c.pb({x[i],y[i]});
        }
    }
    cout<<sol<<endl;
    for(int i=0;i<c.size();i++){
        cout<<c[i].first<< " "<<c[i].second<<endl;
    }
}
