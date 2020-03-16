//Created by Visual Studio Code
//Author: wdvxdr
//Date: 2020-03-16 19:36:01 

#include<bits/stdc++.h>

using namespace std;

const int maxm = 1e6+7,maxn=4e4+7;

struct edge
{
    int v,next;
}e[maxm<<1];

int n,m,head[maxn],vis[maxn],cnt;
bool cl[maxn];

inline void add(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
}

void init()
{
    memset(e,0,sizeof(e));
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(cl,0,sizeof(cl));
    cnt = 0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
}

bool dfs(int u)
{
    vis[u] = 1;
    bool flag = 0;
    for(int i=head[u];i;i=e[i].next)
    {
        int v = e[i].v;
        if(vis[v]&&cl[u] == cl[v])
            flag = 1;
        else if(!vis[v])
        {
            cl[v] = !cl[u];
            flag = flag || dfs(v);
        }
        if(flag)
            break;
    }
    return flag;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        init();
        int flag = 0;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dfs(i))
                flag |= 1;
        if(flag)
            printf("Wrong\n");
        else
            printf("Correct\n");
    }
    return 0;
}