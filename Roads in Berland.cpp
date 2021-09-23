  /*
  
  the problem is that i have a graph with its shortest pathes and i will add edges with smaller weights and i need to know the new total distance
  
  
  */
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
 
    int n;
    cin>>n;
    vector<vector<int>>dis(n,vector<int>(n,oo));
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
    for(int i=0; i<q; i++)
    {
        lld sol=0;
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        dis[a][b]=dis[b][a]=min(dis[a][b],c);
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                dis[u][v]=min({dis[u][v],dis[u][a]+dis[a][b]+dis[b][v],dis[u][b]+dis[b][a]+dis[a][v]});
            }
        }
        for(int g=0;g<n;g++){
            for(int j=g+1;j<n;j++){
                sol+=dis[g][j];
            }
        }
        cout<<sol<<" "<<endl;
 
    }
 
}
