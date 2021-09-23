/*
  the target is to find the greatest path possible and if there is a positive cycle
*/
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
const lld loo=0x3f3f3f3f3f3f3f3f;
int n,m;
vector<pair<lld,pair<int,int>>>gp;
pair<bool,int> bellman(int src,int tar)
{
    vector<lld>dis(n,loo);
    dis[src]=0;
    for(int i=0; i<n-1; i++)
    {
        bool isupdated=0;
        for(auto e:gp)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first)
            {
                dis[e.second.second]=dis[e.second.first]+e.first;
                isupdated=1;
            }
        }
        if(isupdated==0)
        {
            break;
        }
    }
    vector<bool>hasCycle(n,0);
    for(int i=0; i<n; i++)
    {
        for(auto e:gp)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first)
            {
                dis[e.second.second]=dis[e.second.first]+e.first;
                hasCycle[e.second.second]=1;
            }
            if(hasCycle[e.second.first]){
                 hasCycle[e.second.second]=1;
            }
        }
    }
    return{hasCycle[tar],dis[tar]};
}
int main()
{
    cin>>n>>m;
    gp.resize(n);
    for(int i=0; i<m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        --u,--v;
        gp.pb({-c,{u,v}});
    }
    pair<bool,int> ans=bellman(0,n-1);
    if(ans.first)
        cout<<"inf"<<endl;
    else
        cout<<-ans.second<<endl;
}
