#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
#define sbe(x) sort(x.rbegin(),x.rend())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<int>>dis;
const int OO=0x3f3f3f3f,MOD=1e9+7;
const ll loo=0x3f3f3f3f3f3f3f3f;
//const int N=25,M=25;
//int m,c,price[25][25];
//vector<vector<int>> mem;
int M, C, price[25][25]; // price[g (<= 20)][model (<= 20)]
int memo[210][25]; // TOP-DOWN: dp table memo[money (<= 200)][g (<= 20)]
int shop(int money,int g){
    if(money<0)return -1000000000;
    if(g==C) return M-money;
    if(memo[money][g]!=-1)return memo[money][g];
    int ans=-1;
    for(int model=1;model<=price[g][0];model++){
        ans=max(ans,shop(money-price[g][model],g+1));
    }
    return memo[money][g]=ans;
}
int main()
{
    FIO
    /*freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);*/
    int i, j, TC, score;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &M, &C);
        for (i = 0; i < C; i++)
        {
            scanf("%d", &price[i][0]); // store K in price[i][0]
            for (j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
        }
        memset(memo, -1, sizeof memo);
        score = shop(M, 0); // start the top-down DP
        if (score < 0) printf("no solution\n");
        else printf("%d\n", score);
    }


}
