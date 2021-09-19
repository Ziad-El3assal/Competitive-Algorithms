#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
//this vlaue if multiblied by 2 or 3 it will no cause overflow
const int oo=0x3f3f3f3f;
int n,m;
vector<vector<pair<int,int>>> gp;
lld dijsktra(int src,int tar)
{
    vector<lld>dis(n,oo);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,src});
    dis[src]=0;
    while(!q.empty())
    {
        int u= q.top().second;
        int c=q.top().first;
        q.pop();
        if(u==tar) return c;
        // if i get to z same node wiz different value n i dont need it
        // z code might work but wiz more time
        if(c!=dis[u])continue;

        for(auto p:gp[u])
        {
            int v=p.second;
            int vc=p.first;
            if(dis[v]>dis[u]+vc)
            {
                dis[v]=dis[u]+vc;
                q.push({dis[v],v});
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int src,tar;
        cin>>src>>tar;
        --src,--tar;
        gp.clear();
        gp.resize(n);
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            --u,--v;
            gp[u].pb({c,v});
            gp[v].pb({c,u});
        }
         lld x= dijsktra(src,tar);
         x==-1 ?cout<<"NONE"<<endl:cout<<x<<endl;
    }



}
