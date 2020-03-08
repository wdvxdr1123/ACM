//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-04 15:16:11 
#include<bits/stdc++.h>

using namespace std;

const int maxn =1e2+7;

int n,m,p[maxn],h[maxn],c[maxn],dp[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&p[i],&h[i],&c[i]);
        for(int i=1;i<=m;i++)
        	for(int j=1;c[i]>0;j<<=1)
        	{
        		int o = min(j,c[i]);
        		for(int k=n;k>=o*p[i];k--)
        			dp[k] = max(dp[k-o*p[i]]+o*h[i],dp[k]);
        		c[i]-= o;
			}
        cout << dp[n] << endl;
    }
    return 0;
}
