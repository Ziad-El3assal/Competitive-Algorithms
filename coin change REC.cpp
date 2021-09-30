#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
const ll loo=0x3f3f3f3f3f3f3f3f;
int n;
int coins[]= {1,5,10,25,50};
vector<vector<ll>>mem(5,vector<ll>(30000+1, -1));
ll sol(int cur,int rem)
{
    if(cur>=5) return 0;
    if(rem<=0) return 1;
    if(mem[cur][rem]!=-1)
        return mem[cur][rem];
    ll op1=(rem-coins[cur]>=0) ? sol(cur,rem-coins[cur]):0;
    ll op2=sol(cur+1,rem);
    return mem[cur][rem]= op1+op2;
}
int main()
{

    int n;
    while(cin>>n)
        if(sol(0,n)==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else
            cout<<"There are "<<sol(0,n)<<" ways to produce "<<n<<" cents change."<<endl;
}
