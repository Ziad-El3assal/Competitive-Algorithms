#include <bits/stdc++.h>
#include <string>
//#include "Trie.h"
using namespace std;
typedef long long int ll;
typedef double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define sbe(x) sort(x.rbegin(), x.rend())
#define FIO                       \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);                   \
        cout.tie(0);
#define q     \
        int t;    \
        cin >> t; \
        while (t--)
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvpll vector<vector<pair<ll, ll>>>
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5, M = 1e5 + 5, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long double ESP = 1e-8;
vector<int> fenwickx;
vector<int>fenwicky;
int freqx[N];
int freqy[N];
void Update_Fenwick_Tree(int index,int n,int value,vector<int>&fenwick){
    for(int i=index;i<=n;i+=(i&-i)){
        fenwick[i]+=value;
    }
}
void Build_Fenwick_Tree(int n,vector<ll>a){
    fenwickx=vector<int>(n+1,0);
    fenwicky=vector<int>(n+1,0);
    for(int i=1;i<=n;i++){
        Update_Fenwick_Tree(i,n,a[i],fenwickx);
        Update_Fenwick_Tree(i,n,a[i],fenwicky);
    }
}
ll Prefix_Sum(int index,vector<int>&fenwick){
    ll ret=0;
        for(int i=index;i>=1;i-=(i&-i)){
            ret+=fenwick[i];
        }
        return ret;
}
ll Range_Sum(int l,int r,vector<int>&fenwick){
    return Prefix_Sum(r,fenwick)-Prefix_Sum(l-1,fenwick);
}
vector<ll>a;
int main()
{
    FIO
    int n,qq;
    cin>>n>>qq;
    a=vector<ll>(n+1,0);
    Build_Fenwick_Tree(n,a);
    for(int i=0;i<qq;i++)
    {
        int tt;
        cin>>tt;
        if(tt==1)
        {
            int x,y;
            cin>>x>>y;
            freqx[x]++;freqy[y]++;
            if(freqx[x]==1)Update_Fenwick_Tree(x,n,1,fenwickx);
            if(freqy[y]==1)Update_Fenwick_Tree(y,n,1,fenwicky);
        }
        else if(tt==2)
        {
            int x,y;
            cin>>x>>y;
            freqx[x]--;freqy[y]--;
            if(!freqx[x])Update_Fenwick_Tree(x,n,-1,fenwickx);
            if(!freqy[y])Update_Fenwick_Tree(y,n,-1,fenwicky);

        }

        else
        {
            int x1,y1;
            int x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if((abs(Range_Sum(x1,x2,fenwickx))==abs(x2-x1+1))||(abs(Range_Sum(y1,y2,fenwicky))==abs(y2-y1+1)))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            /*if(abs(Range_Sum(x2,x1,fenwickx))==abs(x2-x1+1)||abs(Range_Sum(y2,y1,fenwicky))==abs(y2-y1+1))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;*/
        }
    }
}

