/*
  the problem is to delete edges from the graph and count sum allshortest distances
  so i added them reversly so that i can get the sum of each 
*/
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
vector<vector<lld>>dis;
int main()
{
    cin>>n;
    dis=vector<vector<lld>>(n,vector<lld>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>dis[i][j];
        }
    }
    vector<int>rem(n);
    for(int i=0; i<n; i++)
    {
        cin>>rem[i];
    }
    vector<lld>ans;
    vector<bool>added(n,0);
    for(int i=n-1;i>=0;i--){
        int k=rem[i]-1;
        lld sum=0;
        added[k]=1;
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
                if(added[u]&&added[v])
                    sum+=dis[u][v];
            }
        }
        ans.pb(sum);
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }

}
