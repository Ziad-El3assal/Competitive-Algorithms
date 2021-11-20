/*
  the target of the problem is to finf for any prefix of string s which matches suffix of s and number of their occurence
*/
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
vector<pair<int,int>> buildZ(string s)
{
    int n=s.size();
    vector<int>Z(n);
    priority_queue<int>q;
    int l=0,r=0,cnt=0;
    Z[0]=0;
    vector<pair<int,int>>ans;
    for(int i=1; i<n; i++)
    {
        int k=i-l;
        if(i>=r||i+Z[k]>=r)
        {
            l=i;
            r=max(r,i);
            while(r<n&&s[r-l]==s[r])r++;
            Z[i]=r-l;
        }
        else
            Z[i]=Z[k];

        if(Z[i])q.push(Z[i]);
        if(i+Z[i]==n)
        {
            while(!q.empty()&&q.top()>=Z[i])
            {
                cnt++;
                q.pop();
            }
            ans.pb({Z[i],cnt+1});
        }
    }
    reverse(ans.begin(),ans.end());
    ans.pb({n,1});
    return ans;


}
int main(void)
{
    FIO
    string s;
    cin>>s;
    vector<pair<int,int>>ans=buildZ(s);
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
}

