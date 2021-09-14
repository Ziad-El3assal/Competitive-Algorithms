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
int max_char=26;
vector<int> computeprefix(string pat)
{
    int m=pat.size();
    vector<int>longestperfix(m);
    for(int i=1,k=0; i<m; i++)
    {
        while(k>0&&pat[k]!=pat[i])
        {
            k=longestperfix[k-1];
        }
        if(pat[k]==pat[i])
            longestperfix[i]= ++k;
        else
        {
            longestperfix[i]=k;
        }
    }
    return longestperfix;
}
vector<int> KMP(string str,string pat)
{
    int n=str.size();
    int m=pat.size();
    vector<int>sol;
    vector<int>longestperfix=computeprefix(pat);
    for(int i=0,k=0; i<n; i++)
    {
        while(k>0&&pat[k]!=str[i])
        {
            k=longestperfix[k-1];
        }
        if(pat[k]==str[i]) k++;
        if(k==m)
        {
            sol.push_back(k-m+1);
            k=longestperfix[k-1];
        }
    }
    return sol;
}
void printnum(int n,int len)
{
    if(!len) return;
    printnum(n>>1,len-1);
    cout<<(n&1);
}
int sol=0;
int getsi(int n)
{
    if(!n)return sol;
    sol++;
    getsi(n>>1);

}

int coutones(int n)
{
    if(!n) return sol;
    if((n&1)==1)sol++;
    coutones((n>>1));
}
int graycode(int i)
{
    return i^(i>>1);
}
int r=0;
int getnumofd(int x)
{
    if(!x)return r;
    r++;
    getnumofd(x>>1);
}
void printallsets(int len)
{

    for(int i=(1<<len)-1; i>=0; i--)
    {
        printnum(graycode(i),len);
        cout<<" ";
        sol=0;
        cout<<coutones(graycode(i))<<endl;
    }
    cout<<endl;
}

void printallsubmasks(int mask)
{
    r=0;
    int x=getnumofd(mask);
    for(int submask=mask; submask; submask=(submask-1)&mask)
    {

        printnum(submask,x);
        cout<<endl;
    }
}
vector<int>par,sz;
int findpar(int u)
{
    if(u==par[u])
        return u;
    return par[u]=findpar(par[u]);
}
void join(int a,int b)
{
    a=findpar(a);
    b=findpar(b);
    if(a!=b)
    {
        if(sz[a]>sz[b])
        {
            swap(a,b);
        }
        par[a]=b;
        sz[b]+=sz[a];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        par.resize(n);
        iota(par.begin(),par.end(),0);
        sz=vector<int>(n,1);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            join(u,v);
        }
        int mx=0;
        for(int i=0; i<n; i++)
        {
            mx=max(mx,sz[findpar(par[i])]);
        }
        cout<<mx<<endl;
    }
}



