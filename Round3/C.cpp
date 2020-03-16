//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-13 19:07:49 

#include<bits/stdc++.h>

using namespace std;

const int maxn = 507;

int e,f,n,p[maxn],w[maxn],dp[10007];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&e,&f);
        int o=f-e;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i],&w[i]);
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=o;j++)
                dp[j] = min(dp[j],dp[j-w[i]]+p[i]);
        if(dp[o]==0x3f3f3f3f)
            cout << "This is impossible.\n";
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[o]);
    }
    return 0;
}