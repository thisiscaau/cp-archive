#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
int const N=30,M=2e5+1;
struct tree{ int son[2],d; }t[N*M];
int n;
ll ans,root,tot,r,mi[N],a[M];
void merge(int x,int y,ll k)
{
    if (t[x].d==N) { r=min(r,k); return; }
    bool flag=false;
    for (int i=0;i<=1;i++) if (t[x].son[i]&&t[y].son[i]) merge(t[x].son[i],t[y].son[i],k),flag=true;
    if (!flag)
    {
        if (t[x].son[0]&&t[y].son[1]) merge(t[x].son[0],t[y].son[1],k+mi[N-t[x].d-1]); else merge(t[x].son[1],t[y].son[0],k+mi[N-t[x].d-1]);
    }
}
void dfs(int x)
{
    if (!x||t[x].d==N) return;
    for (int i=0;i<=1;i++) dfs(t[x].son[i]);
    if (t[x].son[0]&&t[x].son[1]) r=2e9,merge(t[x].son[0],t[x].son[1],mi[N-t[x].d-1]),ans+=r;
}
int main()
{
    mi[0]=1; for (int i=1;i<N;i++) mi[i]=mi[i-1]*2;
    scanf("%d",&n),root=tot=1;
    for (int i=1,x;i<=n;i++)
    {
        scanf("%lld",&a[i]),x=root;
        for (int j=0;j<N;j++)
        {
            int r=((mi[N-j-1]&a[i])>0);
            if (!t[x].son[r]) t[x].son[r]=++tot,t[tot].d=t[x].d+1;
            x=t[x].son[r];
        }
    }
    dfs(1),printf("%lld",ans);
}