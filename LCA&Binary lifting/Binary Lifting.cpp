/*
i need to find the kth ancestor of a node for differemt queries O(nlon(maxn))
*/
#include <bits/stdc++.h>
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
int m;
vector<vector<int>>gp;
vector<int>depth;
vector<vector<int>> anc;
// getting the log of input O(1)
int Log(int x){
    return 31-__builtin_clz(x);
}
void DFS(int u,int p){
    for(auto v:gp[u]){
        //as it a tree it doesn't matter to check parent of every node it can be done with array of visited nodes as ordinary dfs 
        if(v==p)
            continue;
        //construct the depth of each node 
        depth[v]=depth[u]+1;
        //here constructing sparse concept that the  the first anscetor of my first ansector is my second ancestor 
        /*
                    
           0
         /   \
        3      2
       / \       \
      5   4       6  
     / \
    1   7
    nodes 0 1 2 3 4 5 6 7 
p2s  2^0  0 5 0 0 3 3 2 5 
     2^1  1 3 0 0 0 0 0 3
     2^2  2 0 0 0 0 0 0 0
     2^3  3 0 0 0 0 0 0 0
     2^4  4 0 0 0 0 0 0 0
       .  5 0 0 0 0 0 0 0
       .  6 0 0 0 0 0 0 0
       .  7 0 0 0 0 0 0 0
       .  8 0 0 0 0 0 0 0
       .  9 0 0 0 0 0 0 0
       .  10 0 0 0 0 0 0 0
       .  11 0 0 0 0 0 0 0
       .  12 0 0 0 0 0 0 0
       .  13 0 0 0 0 0 0 0
       .  14 0 0 0 0 0 0 0
       .  15 0 0 0 0 0 0 0
       .  16 0 0 0 0 0 0 0
       .  17 0 0 0 0 0 0 0
       the third ancestor of 3 is reprsented in binary as 101 
       so the 3rd ancestor is the second ancestor of my first ancsetor and this is shown in the multi dimensional array shown
        
        
        
        */
      //the 2^0 ancestor of the cild is its parent
        anc[v][0]=u;
      // update all ansector 
        for(int i=1;i<m;i++){
            anc[v][i]=anc[anc[v][i-1]][i-1];
        }
        DFS(v,u);
    }   
}
int k_ancestor(int u,int k){
  /*
  kth ancestor is represented in binary in each value that is equal to one i move to 1 shifted lift with it which is equal to the binary ancestor 
    eg  third ancestor of 1
        3=101 
        k&(1<<0)=1
          so u =anc[1][0]=5
        k&(1<<2)=1
        u=anc[5][2]=0
        return 0
  */
    if(k>depth[u])return -1; 
    for(int i=0;i<m;i++){
        if(k&(1<<i)){
            u=anc[u][i];
        }
    }
    return u;
}

int main(void)
{
    FIO
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;cin>>n;
    gp.resize(n);
    m=Log(n)+1;
    depth=vector<int>(n);
    anc=vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u,--v;
        gp[u].push_back(v);
        gp[v].push_back(u);    
    }
    int rot=0;
    depth[rot]=0;
    anc[rot][0]=rot;
    DFS(0,-1);
    int c;
    cin>>c;
    while(c--){
        int x,y;
        cin>>x>>y;
        x--;
        int sol=k_ancestor(x,y);
        (sol==-1)? cout<<-1<<endl:cout<<sol+1<<endl;
    }

    
}
