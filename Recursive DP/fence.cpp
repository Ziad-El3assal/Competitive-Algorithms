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
const int N=4e4+7,M=2e2+7;
int n,a,b,arr[N];
int mem[M][N][2];
int solve(int i, int remR, int remG, bool nxtR)
{
    if(i==0) return 0;
    if(mem[i][remG][nxtR]!=-1) return mem[i][remG][nxtR];
    int op1=OO,op2=OO;
    if(remG>=arr[i])
    {
        op1= solve(i-1,remR,remG-arr[i],0);
        if(nxtR)
            op1+=min(arr[i],arr[i+1]);
    }
    if(remR>=arr[i])
    {
        op2= solve(i-1,remR-arr[i],remG,1);
        if(!nxtR)
            op2+=min(arr[i],arr[i+1]);
    }
    return mem[i][remG][nxtR]=min(op1,op2);
}
int main()
{
    FIO
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    cin>>n>>a>>b;
    memset(mem,-1,sizeof mem);
    for(int i=1; i<=n; i++)cin>>arr[i];
    int ans=solve(n,a,b,0);
    if(ans<OO)
        cout<<ans<<endl;
    else cout<<-1<<endl;

}
