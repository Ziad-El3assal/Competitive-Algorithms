#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
typedef double ld;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int OO=0x3f3f3f3f,MOD=1e9+7;
const long double EPS=1e-8;
const ll loo=0x3f3f3f3f3f3f3f3f;
ll egcd(ll a, ll b, ll &x, ll &y)  /// ax + by = gcd(a,b)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll g=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

ll modInverse(ll a, ll m)  /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
{
    ll x,y,g;
    g=egcd(a,m,x,y);
    if(g>1)
        return -1;
    return (x+m)%m;
}
ll fixMod(ll a, ll m)
{
    return (a + m)%m;
}
ll PushFront(ll h,ll xp,char ch,ll p)
{
    return (h+(xp*ch)%p)%p;
}
ll PopBack(ll h,ll x,char ch,ll p)
{
    return (fixMod(h-ch,p)*modInverse(x,p))%p;
}
ll PushBack(ll h, ll x, ll p, char ch){
    return (((h*x)%p)+ch)%p;
}
ll popFront(ll h,ll xp,ll p,char ch ){
    return fixMod(h-((xp*ch)%p),p);
}

int main()
{
    FIO
    ll x=128, p1=1e9+7, p2=1e9+9;
    vector<ll>xp1(1e5+1),xp2(1e5+1);
    xp1[0]=xp2[0]=1;
    for(int i=1; i<100000; i++)
    {
        xp1[i]=(x*xp1[i-1])%p1;
        xp2[i]=(x*xp2[i-1])%p2;
    }
    /*freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);*/
    int t;cin>>t;
    while(t--){
        string z,y;
        cin>>z>>y;
        int n=z.size();
        int m=y.size();
        ll hy=0,hz=0;
        for(int i=0;i<m;i++){
           hy=PushBack(hy,x,p1,y[i]);
        }
        for(int i=0;i<min(n,m);i++){
            hz=PushBack(hz,x,p1,z[i]);
        }
        vector<int>ans;
        if(hy==hz)ans.pb(1);
        for(int i=m;i<n;i++){
            hz=popFront(hz,xp1[m-1],p1,z[i-m]);
            hz=PushBack(hz,x,p1,z[i]);
            if(hz==hy)
                ans.pb(i-m+2);
        }
        if(ans.size()==0)
            cout<<"Not Found"<<endl<<endl;
        else{
            cout<<ans.size()<<endl;
            for(auto i:ans)cout<<i<<" ";
            cout<<endl<<endl;
        }

    }
}
