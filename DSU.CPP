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
#endif}

vector<int> par,sz;
int fidpar(int u)
{
    if(u==par[u])
        return u;
    // if i am not the aprent of me so i have a parent
    else
        return par[u]=fidpar(par[u]);
}
bool isConected=0;
void join(int a,int b)
{
    //because I'll only deal with parents , I'll make use of the parameters variables instead of initializing new ones
    a=fidpar(a);
    b=fidpar(b);
    //this condition is to make shure not to connect the larger component with the lower so it will be bad for time 
    //doing so we will always connect the smaller component to the bigger one
    if(a!=b){
        if(sz[a]>sz[b])
        swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    par.resize(n);
    sz=vector<int>(n,1);
    // intialize each element to be his parent
    iota(par.begin(),par.end(),0);
    while(q--){
        int t,u,v;
        if(t==1){
            // join the two nodes make the parent 
            join(u,v);
        }
        else
        {
            //if they have the same parent they are connected
            if(fidpar(u)==fidpar(v)){
                cout<<1<<endl;
            }
            else cout<<0;
        }
    }
}



