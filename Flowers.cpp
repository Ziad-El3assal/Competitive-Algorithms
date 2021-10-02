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
vector<ll>mem;
int t,k;
ll sol(int i){
    if(i==0)
        return 1;
        if(i<0)return 0;
    if(mem[i]!=-1) return mem[i];
    ll op1=sol(i-1);
    ll op2=sol(i-k);
    return mem[i]=(op1+op2)%MOD;
}
int main()
{
    cin>>t>>k;
    ll mx=0;
    vector<pair<int,int>>s;
    while(t--){
        int x,y;
        cin>>x>>y;
        s.pb({x,y});
        ll c =max(x,y);
        mx=max(c,mx);
    }
    mem=vector<ll>(mx+2,-1);
    sol(mx);
    mem[0]=0;
    for(int i=0;i<mx+1;i++){
        mem[i]+=mem[i-1];
    }
    for(auto e:s){
        cout<<(mem[e.second]-mem[e.first-1])%MOD<<endl;
    }

}
