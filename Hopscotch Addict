#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int lld;
void run()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef Local
    freopen("input.txt", "r", stdin);
#else
#endif
}
#define sz(x) x.size();
const int N=2e4+5;
vector<vector<int>> gp;
vector<bool> visited;
vector<int>stck;
bool isAcyclic=1;
int cnt=0;
int n,m;
unordered_map<string,int>mp;
int BFS(int s,int t){
    queue<int>q;
    vector<int>dis(3*n,-1);
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==t){
            return dis[t]/3;
        }
        for(auto v:gp[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    gp.clear();
    visited=vector<bool>(n,0);
    gp.resize(3*n);
    for(int i=0; i<m; i++)
    {
        int u,v;cin>>u>>v;
        --u,--v;
        gp[u*3].push_back(v*3+1);
        gp[u*3+1].push_back(v*3+2);
        gp[u*3+2].push_back(v*3);
    }
    int s,t;
    cin>>s>>t;
    s--,t--;
    int x=BFS(3*s,3*t);
    cout<<x;

}
