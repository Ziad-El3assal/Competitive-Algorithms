#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
 
const int N=1e5+5, M=1e3+5, MOD=1e9+7,OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
 
int n,m;
string s,p;
vector<int>prefix,Z;
 
void buildPrefix(){
    prefix=vector<int>(n);
    int border=0;
    prefix[0]=0;
    for(int i=1; i<n; i++){
        while(border>0 && s[i]!=s[border]) border=prefix[border-1];
        if(s[i]==s[border]) border++;
        prefix[i]=border;
    }
}
 
void buildZ(){
    Z=vector<int>(n);
    int l=0,r=0;
    Z[0]=0;
    for(int i=1; i<n; i++){
        int k=i-l;
        if(i>=r || i+Z[k]>=r){
            l=i;
            r=max(r,i);
            while(r<n && s[r-l]==s[r]) r++;
            Z[i]=r-l;
        }
        else
            Z[i]=Z[k];
    }
}
 
 
 
 
int main(){
    FIO 
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>s>>p;
    s=p+'$'+s;
    n=s.length();
    m=p.length();
 
    buildZ();
    for(int i=m+1; i<n; i++)
        if(Z[i]==m) cout<<i-(m+1)<<' ';
    cout<<'\n';
 
    buildPrefix();
    for(int i=m+1; i<n; i++)
        if(prefix[i]==m) cout<<i-2*m<<' ';
    cout<<'\n';
 
 
    return 0;
}
