#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
const lld loo=0x3f3f3f3f3f3f3f3f;
int n;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n+5);
    for(int i=1; i<=n; i++)cin>>a[i];
    a[0]=0;
    vector<vector<lld>>dp(n+5,vector<lld>(n+5,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
           // cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<endl;
            if(a[i]>a[j])
                dp[i+1][i]=max(dp[i+1][i],dp[i][j]+1);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            /*for(int u=0;u<n+2;u++){
                for(int v=0;v<n+2;v++)
                    cout<<dp[u][v]<<" ";
                cout<<endl;
            }*/
        }
    }

    lld mx=1;
    for(int i=0;i<=n;i++)
        mx=max(dp[n+1][i],mx);
    cout<<mx<<endl;
}
