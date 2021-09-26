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
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        vector<int>w(n),v(n);
        for(int i=0; i<n; i++)
        {
            cin>>w[i]>>v[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                if(j+w[i]<=k){
                    dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
                   //  cout<<"dp["<<i+1<<"]["<<j+w[i]<<"]= "<<max(dp[i+1][j+w[i]],dp[i][j]+v[i])<<endl;
                     }

                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                    // cout<<"dp["<<i+1<<"]["<<j<<"]= "<<max(dp[i+1][j],dp[i][j])<<endl;
            }
           // cout<<"step "<<i<<endl;
           /* for(int u=0;u<=n;u++){
                for(int v=0;v<=k;v++){
                    cout<<dp[u][v]<<" ";
                }
                cout<<endl;
            }*/
            cout<<dn[n][k];
        }
    }
}
