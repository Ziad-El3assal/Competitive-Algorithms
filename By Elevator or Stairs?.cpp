#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f,MOD=1e9+7;
const ll loo=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+5;
vector<int>a,b,ans;
int n,c;
vector<vector<int>>mem;
int sol(int i, bool islsElv){

    if(i==0)return 0;
    if(mem[i][islsElv]!=-1)
        return mem[i][islsElv];
    int op2=sol(i-1,1)+b[i];
    if(islsElv==0) op2+=c;
    int op1=sol(i-1,0)+a[i];
    return mem[i][islsElv]=ans[i]=min(op1,op2);
}
int main()
{

    cin>>n>>c;
    a.resize(n);
    b.resize(n);
    ans.resize(n);
    mem=vector<vector<int>>(n,vector<int>(2,-1));
    for(int i=1;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        cin>>b[i];
    sol(n-1,0);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}
