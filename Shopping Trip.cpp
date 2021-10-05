#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
typedef double ld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int OO=0x3f3f3f3f,MOD=1e9+7;
const long double EPS=1e-8;
const ll loo=0x3f3f3f3f3f3f3f3f;
int n,m,p;
vector<int>city;
vector<ld>cost;
vector<vector<ld>>dis,mem;
ld solve(int cur,int mask)
{
        if(mask==(1<<p)-1) return dis[city[cur]][city[0]];
        if(mem[cur][mask]!=-loo)return mem[cur][mask];
        ld ret=dis[city[cur]][city[0]];
        for(int nxt=1;nxt<p;nxt++){
                if((mask>>nxt)&1)continue;
            ret=min(ret,dis[city[cur]][city[nxt]]-cost[nxt]+solve(nxt,mask|(1<<nxt)));
        }
        return mem[cur][mask]=ret   ;
}
int main()
{
    FIO
    /*freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);*/
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        n++;
        dis=vector<vector<ld>>(n,vector<ld>(n,loo));
        for(int i=0; i<n; i++)dis[i][i]=0;
        for(int i=0; i<m; i++)
        {
            int u,v;
            ld c;
            cin>>u>>v>>c;
            dis[u][v]=dis[v][u]=min(c,dis[u][v]);
        }
        for(int k=0; k<n; k++)
        {
            for(int u=0; u<n; u++)
            {
                for(int v=0; v<n; v++)
                {
                    dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
                }
            }
        }
        cin>>p;
        p++;
        mem=vector<vector<ld>>(p,vector<ld>(1<<p,-loo));
        city.resize(p);
        cost.resize(p);
        city[0]=0;
        cost[0]=0;
        for(int i=1; i<p; i++)
            cin>>city[i]>>cost[i];
        ld x=-1*solve(0,1<<0);
        if(x>EPS)cout<<fixed<<setprecision(2)<<"Daniel can save $"<<x<<endl;
        else cout<<"Don't leave the house"<<endl;
    }
}
