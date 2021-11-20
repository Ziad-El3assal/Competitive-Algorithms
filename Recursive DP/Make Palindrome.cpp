#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
const int oo=0x3f3f3f3f,MOD=1e9+7;
const ll loo=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+5;
vector<vector<int>>mem;
string s,f,l;
int n;
int sol(int i,int j)
{
    if(i>j) return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(s[i]==s[j])
        return sol(i+1,j-1);
    int op1=sol(i+1,j)+1;
    int op2=sol(i,j-1)+1;
    return mem[i][j]=min(op1,op2);
}
void print(int i,int j)
{
    if(i>j) return ;
    if(s[i]==s[j])
    {
        f+=s[i];
        if(i!=j)
            l=s[i]+l;
        print(i+1,j-1);
        return;
    }
    int opt=sol(i,j);
    int op1=sol(i+1,j)+1;
    int op2=sol(i,j-1)+1;
    if(opt==op1)
    {
        f+=s[i];
        l=s[i]+l;
        print(i+1,j);
        return;
    }
    f+=s[j];
    l=s[j]+l;
    print(i,j-1);

}
int main()
{
    while(cin>>s)
    {
        n=s.length();
        f=l="";
        mem=vector<vector<int>>(n,vector<int>(n,-1));
        print(0,n-1);
        cout<<sol(0,n-1)<<" "<<f<<l<<endl;
    }
}
