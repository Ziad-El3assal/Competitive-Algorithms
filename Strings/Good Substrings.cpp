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
ll PushBack(ll h, ll x, ll p, char ch)
{
    return (((h*x)%p)+ch)%p;
}
ll popFront(ll h,ll xp,ll p,char ch )
{
    return fixMod(h-((xp*ch)%p),p);
}
// to extend the range 2 wiz range one so ican use unordered_set as cpp doesnt suppor unordered set for pairs so the time for sorting in aet is eleminated
ll to(ll h1,ll h2,ll p2){
 return h1*p2+h2;
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
    string s,god;
    int k;
    cin>>s>>god>>k;
    int n=s.length();
    unordered_set<ll> st;
    for(int i=0;i<n;i++){
        ll h1=0,h2=0,cnt=0;
        for(int j=i;j<n;j++){
            h1=PushBack(h1,x,p1,s[j]);
            h2=PushBack(h2,x,p2,s[j]);
            cnt+=(god[s[j]-'a']=='0');
            if(cnt>k)
                break;
            st.insert(to(h1,h2,p2));
        }
    }
    cout<<(int)st.size();
}
