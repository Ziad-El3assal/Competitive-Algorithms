#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;

#define pb push_back
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int N = 5e2 + 20, M = 1e4 + 5, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
int n,m,x,k;
char a[N][N];
bool mark[N][N];
void dfs (int i,int j) {
    if(x==0)return;
    mark[i][j]=true;
    x--;
    for(int u=0;u<4;u++){
        int new_i = i + dx[u];
		int new_j = j + dy[u];
        if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m&&a[new_i][new_j]=='.'&&!mark[new_i][new_j]){
            dfs(new_i,new_j);
        }
    }

}   
int main()
{
    FIO 
    cin>>n>>m>>k;
    int pi,pj,cnt_empty=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                cnt_empty++;
                pi=i,pj=j;
            }
        }
    }
    x=cnt_empty-k;  
    dfs(pi,pj);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mark[i][j]){
                cout<<".";
            }
            else if(a[i][j]=='#'){
                cout<<"#";
            }
            else {
                cout<<"X";
            }
        }
        cout<<endl;
    }
    
    
    return 0;
}
