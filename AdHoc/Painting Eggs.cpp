/*                    A    B                      
	    |A-B|<=500
	    a=in b=in+B
	    if (|A-b|>500) b isnot valid
	    a=in+A b=600
	    if(|a-B|>500) a isnot valid
*/
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
vector<vector<ll>> a, bit;
int main()
{
    FIO
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;cin>>n;
    int A=0,B=0;
    string sol="";
    bool isa=1,isb=1,isval=1;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        isa=1,isb=1;
        int a=x,b=y;
        x+=A;
        if(abs(x-B)>500){
            isa=0;
        }
        y+=B;
        if(abs(y-A)>500){
            isb=0;
        }
        //cout<<y<<" "<<x<<'\n';
        if(!isb&&!isa){
            isval=0;
            continue;
        }
        else if(isa&&!isb){
            A+=a;
            sol+="A";
            continue;
        
        }
        else if(!isa&&isb){
            B+=b;
            sol+="G";
            continue;
        }
        else{
            A+=a;
            sol+="A";
            continue;
        }
    }
    if(isval)
        cout<<sol<<endl;
    else 
        cout<<-1<<'\n';
}
