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
#endif}

vector<int> par,sz;
int fidpar(int u)
{
    if(u==par[u])
        return u;
    else
        return par[u]=fidpar(par[u]);
}
bool isConected=0;
void join(int a,int b)
{
    a=fidpar(a);
    b=fidpar(b);
    if(a!=b){
        if(sz[a]>sz[b])
        swap(a,b);
        par[a]=b;
        sz[b]+=sz[b];
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    par.resize(n);
    sz=vector<int>(n,1);
    iota(par.begin(),par.end(),0);
    while(q--){
        int t,u,v;
        if(t==1){
            join(u,v);
        }
        else
        {
            if(fidpar(u)==fidpar(v)){
                cout<<1<<endl;
            }
            else cout<<0;
        }
    }
}



