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
#define cost first
#define from second.first
#define to  second.second
#define pb push_back
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>gp(n);
        gp.clear();
        queue<int> q;
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            gp[v].pb(u);
            gp[u].pb(v);
        }
        vector<int>parity(n,-1),odd,even;
        q.push(0);
        parity[0]=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(parity[x]&1)
            {
                odd.pb(x);
            }
            else even.pb(x);
            for(int v:gp[x])
            {
                if(parity[v]==-1)
                {
                    parity[v]=1-parity[x];
                    q.push(v);
                }
            }

        }
        if(odd.size()>even.size())
        {
            cout<<even.size()<<endl;
            for(int i=0; i<even.size(); i++)cout<<++even[i]<<" ";
            cout<<endl;
        }
        else
        {
            cout<<odd.size()<<endl;
            for(int i=0; i<odd.size(); i++)cout<<++odd[i]<<" ";
            cout<<endl;
        }

    }


}
