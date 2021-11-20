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
 
    string x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    vector<vector<int>>dis(505,vector<int>(505,oo));
    for(int i=0; i<27; i++) dis[i][i]=0;
    for(int i=0; i<n; i++)
    {
        char s,z;
        cin>>s>>z;
        int c;
        cin>>c;
        dis[s-'a'][z-'a']=min(dis[s-'a'][z-'a'],c);
    }
    if(x.size()!=y.size())
    {
        return cout<<-1<<endl,0;
 
    }
    for(int k=0; k<30; k++)
    {
        for(int u=0; u<30; u++)
        {
            for(int v=0; v<30; v++)
            {
                dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
    int sum=0;
    string sol=x;
    for(int i=0; i<x.size(); i++)
    {
        int mn=oo;
        char c;
        if(x[i]!=y[i])
        {
 
            for(char j='a'; j<='z'; j++)
            {
                if(dis[x[i]-'a'][j-'a']+dis[y[i]-'a'][j-'a']<mn)
                {
                    mn=dis[x[i]-'a'][j-'a']+dis[y[i]-'a'][j-'a'];
                    c=j;
                }
            }
            sum+=mn;
            sol[i]=c;
            if(mn==oo)
            {
                return cout<<-1<<endl,0;
            }
        }
    }
    cout<<sum<<endl;
    cout<<sol<<endl;
 
}
