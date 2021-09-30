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
int mn=1e5+1,mx=0;
int frq[N];
int n,k;
vector<vector<ll>>mem;
ll sol(int i,int j){

    if(j==k)
        return 1;
    if(mem[i][j]!=-1){
        return mem[i][j];
    }
    ll ret=0;
    for(int k=i;k<=n;k+=i){
        ret=(ret+ sol(k,j+1))%MOD;
    }
    return mem[i][j]=ret;

}
int main()
{
    cin>>n>>k;
    mem=vector<vector<ll>>(n+1,vector<ll>(k+1,-1));
    cout<<sol(1,0);
}
