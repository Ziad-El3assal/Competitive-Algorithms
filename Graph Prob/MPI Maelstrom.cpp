  /*
  the problem is that i can move from nodes parrell so when i need to travese all nodes from ost will be the maximum cost from one
  
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
vector<string>p2s;
const lld N=2e18+6;
int main()
{
    int n;
    cin>>n;
    vector<vector<lld>>dis(n,vector<lld>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            string s;
            cin>>s;
            if(s=="x")dis[i][j]=dis[j][i]=loo;
            else
            {
                dis[i][j]=dis[j][i]=stoll(s);
            }
        }

    }
    for(int k=0;k<n;k++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
    cout<<*max_element(dis[0].begin(),dis[0].end())<<endl;
}
