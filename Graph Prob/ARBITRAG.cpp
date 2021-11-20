/*
  the problem is to find maximum product
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
int main()
{
    int cnt=0;
    while(cin>>n,n)
    {
        vector<vector<double>>cost(n,vector<double>(n,0));
        map<string,int>mp;
        for(int i=0; i<n; i++)
        {
            cost[i][i]=1;
            string x;
            cin>>x;
            mp[x]=i;
        }
        int m;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            string y,z;
            double c;
            cin>>y>>c>>z;
            cost[mp[y]][mp[z]]=max(cost[mp[y]][mp[z]],c);
        }
        for(int k=0; k<n; k++)
        {
            for(int u=0; u<n; u++)
            {
                for(int v=0; v<n; v++)
                {
                    cost[u][v]=max(cost[u][v],cost[u][k]*cost[k][v]);
                }
            }
        }
        bool s=0;
        for(int i=0; i<n&&!s    ; i++)
        {
            if(cost[i][i]>1)
            {
                s=1;
                break;
            }
        }


        cout<<"Case "<<++cnt<<": ";s?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }

}
