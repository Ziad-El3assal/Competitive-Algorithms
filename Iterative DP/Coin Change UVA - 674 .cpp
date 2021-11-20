    #include <iostream>
    #include<bits/stdc++.h>
    #include <vector>
    using namespace std;
    typedef long long int lld;
    #define pb push_back
    #define sbe(x) sort(x.rbegin(),x.rend())
    const int oo=0x3f3f3f3f;
    const lld loo=0x3f3f3f3f3f3f3f3f;
    int n;
    int main()
    {
        int n;
        while(cin>>n)
        {

            vector<int>dp(n+1,0);
            int coins[]= {1,5,10,25,50};
            dp[0]=1;
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<=n; j++)
                {
                    if(j+coins[i]<=n)
                    {
                        dp[j+coins[i]]+=dp[j];
                    }
                }

            }
            cout<<dp[n]<<endl;

        }

    }
