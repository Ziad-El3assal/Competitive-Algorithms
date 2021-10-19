#include <bits/stdc++.h>
//#include "Trie.h"
using namespace std;
typedef long long int ll;
typedef double ld;
#define pb push_back
#define sbe(x) sort(x.rbegin(), x.rend())
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int OO = 0x3f3f3f3f, MOD = 1e9 + 7;
const long double EPS = 1e-8;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int sparse[N][17];
int n;
vector<int> a;
int lo2[N + 1];
void ConstructSparseTaple()
{
    for (int i = 0; i < a.size(); i++)
    {
        sparse[i][0] = a[i];
    }
    for (int j = 1; j < 17; j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        {
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    lo2[1] = 0;
    for (int i = 2; i <= N; i++)
        lo2[i] = lo2[i / 2] + 1;
}
int main(void)
{
    FIO
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        int n;
    cin >> n;
    a = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ConstructSparseTaple();
    int q;cin>>q;
    cout<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        int j=lo2[r-l+1];
        cout<<min(sparse[l][j],sparse[r-(1<<j)+1][j])<<endl;
    }
}
