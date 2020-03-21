//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-18 21:31:17 

#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 1e4+7;

struct edge
{
    int v,next;
}e[maxn];

int head[maxn],cnt,deg[maxn],vis[maxn],n;
queue<int> q;

void add(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
    deg[v]++;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        while(scanf("%d",&t))
        {
            if(t)   add(i,t);
            else    break;
        }
    }
    for(int i=1;i<=n;i++)
        if(!deg[i])
            q.push(i);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v = e[i].v;
            if(--deg[v] == 0)
                q.push(v);
        }
        printf("%d ",x);
    }
    return 0;
}