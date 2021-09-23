/*
the problem is to find the maximum edge in the shortest path
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
vector<string>p2s;
const lld N=2e18+6;
int main()
{

    int n,m,q;
    int cnt=0;
    while(cin>>n>>m>>q && n||m||q)
    {
        vector<vector<lld>>dis(n,vector<lld>(n,loo));
        for(int i=0;i<n;i++){dis[i][i]=0;}
        for(int i=0;i<m;i++){
            lld u,v,c;
            cin>>u>>v>>c;
            --u,--v;
            dis[u][v]=dis[v][u]=min(dis[u][v],c);
        }
        for(int k=0;k<n;k++){
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    dis[u][v]=min(dis[u][v],max(dis[u][k],dis[k][v]));
                }
            }
        }
        if(cnt) cout<<endl;
        cout<<"Case #"<<++cnt<<endl;
        while(q--){
            int u,v;
            cin>>u>>v;
            --u,--v;
            if(dis[u][v]>=loo){
                cout<<"no path"<<endl;
            }
            else cout<<dis[u][v]<<endl;
        }
    }
}
