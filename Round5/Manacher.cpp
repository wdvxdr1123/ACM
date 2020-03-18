//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-18 18:21:20 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 3e6+5;

char a[maxn],c[maxn];
int p[maxn],id,mx,len1,len2,ans;

void init()
{
    memset(c,0,sizeof(c));
    c[0] = '@',c[1]='#';
    len1 = strlen(a);
    for(int i=0;i<len1;i++)
        c[i*2+2] = a[i],c[i*2+3]='#';
    len2 = len1*2+2;
    c[len2] = '$';
}

void manacher()
{
    id =0,mx=0,ans=0;
    for(int i=1;i<len2;i++)
    {
        if(mx > i)  p[i] = min(p[id*2-i],mx-i);
        else    p[i] = 1;
        for(;c[i+p[i]]==c[i-p[i]];p[i]++);
        if(p[i]+i>mx)
        {
            mx = p[i]+i;
            id = i;
        }
        ans = max(ans,p[i]);
    }
}

int main()
{
    for(int i=1;;i++)
    {
        memset(a,0,sizeof(a));
        scanf("%s",a);
        if(a[0]=='E')   break;
        init();
        manacher();
        printf("Case %d: %d\n",i,ans-1);
    }
    return 0;
}