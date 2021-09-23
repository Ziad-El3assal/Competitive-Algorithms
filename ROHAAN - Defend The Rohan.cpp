#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
 
int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>dis(n,vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>dis[i][j];
            }
        }
        for(int k=0; k<n; k++)
        {
            for(int u=0; u<n; u++)
            {
                for(int v=0; v<n; v++)
                {
                    dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
                }
            }
        }
        int q;
        cin>>q;
        int sum=0;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            sum+=dis[u][v];
        }
        cout<<"Case #"<<++cnt<<": "<<sum<<endl;
    }
 
}
 
