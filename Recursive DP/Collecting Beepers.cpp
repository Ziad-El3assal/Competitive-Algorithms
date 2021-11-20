#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int OO=0x3f3f3f3f,MOD=1e9+7;
const ll loo=0x3f3f3f3f3f3f3f3f;
int n;
vector<int>x,y;
int dis(int ax,int ay,int bx,int by)
{
    return abs(ax-bx)+abs(ay-by);
}
vector<vector<int>>mem;
int solve(int cur,int mask){
    if(mask==(1<<n)-1) return dis(x[cur],y[cur],x[0],y[0]);
    if(mem[cur][mask]!=-1) return mem[cur][mask];
    int ret =OO;
    for(int nxt=0;nxt<n;nxt++){
        if((mask>>nxt)&1) continue;
        ret=min(ret,solve(nxt,mask|(1<<nxt))+dis(x[cur],y[cur],x[nxt],y[nxt]));
    }
    return mem[cur][mask]=ret;
}
int main()
{
    FIO
    /*freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);*/
    int t;
    cin>>t;
    while(t--){
            int sx,sy;
        cin>>n>>n>>sx>>sy>>n;
        n++;
        x.resize(n),y.resize(n);
        x[0]=sx,y[0]=sy;
        for(int i=1;i<n;i++){
            cin>>x[i]>>y[i];
        }
        mem=vector<vector<int>>(n,vector<int>(1<<n,-1));
        cout<<"The shortest path has length "<<solve(0,1)<<endl;
    }
}
