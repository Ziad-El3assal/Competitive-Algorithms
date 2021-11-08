/*the problem is to detect the -ve cycle*/
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
#define cost first
#define from second.first
#define to second.second
const int oo=0x3f3f3f3f;
int n,m;
/*
i got n node
-first i intiate dis vector wiz infinty 
-the dis of the src wiz 0
-relax edge n-1 time which is maximum time of relaxtion so no more updates might happen if there is no -ve cylce

*/
vector<pair<int,pair<int,int>>>gp;
bool bellman(int src)
{
    vector<int>dis(n,oo);
    dis[src]=0;
    bool hascycle=0;
    // i say we will iterate n-1 but i will iterate n time as if there is update after n-1 time so there is -ve cycle
    for(int i=1; i<=n; i++)
    {
        //if there is no update happen after relaxing to all nodes so no need to continue as i have reached minimum cost
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
        else if(i==n)
        {
            hascycle=1;
        }
    }
    return hascycle;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        gp.clear();
        gp.resize(n);
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            gp.pb({c, {u,v}});
        }
        if(bellman(0))
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;

    }
}
