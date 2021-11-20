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
int n;
vector<int>x,h;
vector<vector<int>>mem;
int sol(int i,bool ls){

    if(i==n)
        return 0;
    if(mem[i][ls]!=-1)
        return mem[i][ls];
    int op1=sol(i+1,0);
    int op2= (i==n-1)||(x[i+1]>(x[i]+h[i]))? sol(i+1,1)+1:0;
    int op3= (i==0)||(ls&&(x[i]-h[i])>(x[i-1]+h[i-1])||(!ls &&x[i]-h[i]>x[i-1]))? sol(i+1,0)+1:0;
    return mem[i][ls]=max({op1,op2,op3});

}
int main()
{
    cin>>n;
    x.resize(n);
    h.resize(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>h[i];
    }
    mem=vector<vector<int>>(n,vector<int>(2,-1));
    cout<<sol(0,0);
}
