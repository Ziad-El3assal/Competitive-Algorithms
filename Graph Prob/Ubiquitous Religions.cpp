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

int n,m;
vector<int>par,sz;
int findpar(int u)
{
    if(u==par[u])
        return u;
    return par[u]=findpar(par[u]);
}
void join(int a,int b)
{
    a=findpar(a);
    b=findpar(b);
    if(a!=b)
    {
        if(sz[a]>sz[b])

            swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];

    }
}
int main()
{
    int n,m;
            int cnt=0;

    while(cin>>n>>m, n||m)
    {
        par.resize(n);
        sz=vector<int>(n,1);
        iota(par.begin(),par.end(),0);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            join(u,v);
        }
        unordered_set<int> st;
        for(int i=0; i<n; i++)
        {
            st.insert(findpar(i));
        }
        cout<<"Case"<<" "<<++cnt<<":"<<" "<<st.size()<<endl;
    }
}



