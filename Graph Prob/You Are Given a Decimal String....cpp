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
    string s;
    cin>>s;
    int n=s.length();
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            vector<vector<int>>dis(10,vector<int>(110,oo));
            for(int i=0;i<10;i++){
                dis[i][(i+x)%10]=1;
                dis[i][(i+y)%10]=1;
            }
            for(int k=0;k<10;k++){
                for(int u=0;u<10;u++){
                    for(int v=0;v<10;v++){
                        dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
                    }
                }
            }
            int ans=0;
            for(int i=1;i<n&&ans!=-1;i++){
                if(dis[s[i-1]-'0'][s[i]-'0']>=oo) ans=-1;
                else ans+=dis[s[i-1]-'0'][s[i]-'0']-1;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}
