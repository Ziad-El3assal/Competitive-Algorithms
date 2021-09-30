#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f,MOD=1e9+7;
const ll loo=0x3f3f3f3f3f3f3f3f;
const ll N=5e3+5;
int mn=1e5+1,mx=0;
int frq[N];
int n,k;
string s;
vector<int>dp(N,-1);
int sol(int i)
{
    if(i==n)
        return 1;
    if(i>n||s[i]=='0')
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int op1 =sol(i+1);
    int op2=0;
    op2=(s[i]=='1'||s[i]=='2') ?sol(i+2):0;
    return dp[i]=op1+op2;
}
int main()
{


    while(cin>>s,s!="0")
    {
        n=s.length();
        dp=vector<int>(n+2,-1);
        cout<< sol(0)<<endl;
    }

}
