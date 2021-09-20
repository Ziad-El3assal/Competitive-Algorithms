/*
*
*
the problem is dijkstra in two dimensional array to get from the top left to the bottom right with the minimum cost
* 
*
*/


#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f;
int n,m;

vector<vector<int>>grid;
int dr[]= {0,0,1,-1};
int dc[]= {1,-1,0,0};
bool isvalid(int  r,int c)
{
    return r>=0&&r<n&&c>=0&&c<m;
};
int dijkstra(int sr,int sc,int tr,int tc)
{
    vector<vector<int>>dis(n,vector<int>(m,oo));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    dis[sr][sc]=grid[sr][sc];
    q.push({grid[sr][sc],{sc,sr}});
    while(!q.empty())
    {
        int ur=q.top().second.first;
        int uc=q.top().second.second;
        int w=q.top().first;
        q.pop();
        if(uc==tc&&ur==tr) return w;
        if(w!=dis[ur][uc]) continue;
        for(int i=0; i<4; i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            if(isvalid(vr,vc)&&dis[vr][vc]>dis[ur][uc]+grid[vr][vc])
            {
                dis[vr][vc]=dis[ur][uc]+grid[vr][vc];
                q.push({dis[vr][vc],{vr,vc}});
            }

        }

    }
    return dis[tr][tc];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        grid=vector<vector<int>>(n,vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<dijkstra(0,0,n-1,m-1)<<endl;
    }

}
