//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-16 20:28:14 

#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn = 1e6+7;

int n,k,a[maxn],d[maxn],head,tail;

template<typename T>
T read(T &x)
{
	x = 0;int flag=1;char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')flag = -flag;c=getchar();};
	while(c>='0'&&c<='9') x = x*10+c-'0',c=getchar();
	return x*=flag;
}

void solve1()
{
    head = 0;
    tail = -1;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        while(tail>=head && a[d[tail]]>=a[i])
            tail--;
        d[++tail] = i;
        if(i-d[head]==k)
            head++;
        if(i>=k)
            printf("%d ",a[d[head]]);
    }
    printf("\n");
}


void solve2()
{
    head = 0;
    tail = -1;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        while(tail>=head && a[d[tail]]<=a[i])
            tail--;
        d[++tail] = i;
        if(i-d[head]==k)
            head++;
        if(i>=k)
            printf("%d ",a[d[head]]);
    }
    printf("\n");
}

int main()
{
    read(n);read(k);
    for(int i=1;i<=n;i++)
        read(a[i]);
    solve1();
    solve2();
    return 0;
}