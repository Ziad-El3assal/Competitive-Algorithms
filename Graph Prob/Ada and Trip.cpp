//*
/*
*
*
*
 the problem is to find the most distant node and count them
 *
 *
 *
 */
//*
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
int n,m,q;
vector<vector<pair<int,int>>>gp;
pair<int,int> dijkstra(int src){
    vector<int>dis(n,oo);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dis[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int u=q.top().second;
        int c=q.top().first;
        q.pop();
        if(c!=dis[u])continue;
        for(auto p:gp[u]){
            int v=p.second;
            int vc=p.first;
            if(dis[v]>dis[u]+vc){
                dis[v]=dis[u]+vc;
                q.push({dis[v],v});
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        if(dis[i]<oo){
            mx=max(mx,dis[i]);
        }
    }
    int cnt=count(dis.begin(),dis.end(),mx);
    return {mx,cnt};
}
int main()
{
    cin>>n>>m>>q;
    gp.resize(n);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        gp[u].pb({c,v});
        gp[v].pb({c,u});
    }
    for(int i=0;i<q;i++){
        int src;cin>>src;
        pair<int,int>sol=dijkstra(src);
        cout<<sol.first<<" "<<sol.second<<endl;
    }

}
