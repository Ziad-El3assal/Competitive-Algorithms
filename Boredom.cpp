#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
const ll loo=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+5;
int mn=1e5+1,mx=0;
int frq[N];
vector<ll>mem;
ll sol(int i){
    if(i>mx)return 0;
    if(mem[i]!=-1)return mem[i];
    ll op1=sol(i+2)+((ll)i*frq[i]);
    ll op2=sol(i+1);
    return mem[i]=max(op1,op2);

}
int main()
{

   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        mn=min(x,mn);
        mx=max(mx,x);
        frq[x]++;
    }
    mem=vector<ll>(mx+1,-1);
    cout<<sol(mn)<<endl;
}
