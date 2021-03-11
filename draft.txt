#include<bits/stdc++.h>
using namespace std;
const int _=1e6+22;
int fa[1001],g[1001][1001],n,m,Q,anss[_/10],mm,par[1001],sign[1001],cnt;
// 
int rec[1001];
struct Edge{
	int u,v,w;
}e[_],e1[_];
struct MO{
	int u,v,k;
}mo[_];
inline char gc(){
	static char buf[1<<6],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<6,stdin),p1==p2)?EOF:*p1++;
}
template <class T>
inline void read(T&data){
	data=0;
	register char ch=0;
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0'){
		data=(data<<1)+(data<<3)+(ch^48);
		ch=gc();
	}
}
template <class R>
inline void write(R data){
	if(data>9)write(data/10);
	putchar('0'+data%10);
}
bool cmp(register Edge a,register Edge b){return a.w<b.w;}
int fi(register int x){return x==par[x]?x:par[x]=fi(par[x]);}
int main(){
	read(n),read(m),read(Q);
	register int i,u,v,fu,fv,ff,qq,now,LCA,ans,ANS;
	for(i=1;i<=m;++i){
		register Edge & fff=e1[i];
		read(fff.u),read(fff.v),read(fff.w);
	}
	for(i=1;i<=Q;++i){
		register MO& IOI=mo[i]; 
		read(IOI.k),read(IOI.u),read(IOI.v);
		if(IOI.k==2)g[IOI.v][IOI.u]=1,g[IOI.u][IOI.v]=1;
	}
	for(i=1;i<=m;++i){
		register int &IOI=g[e1[i].u][e1[i].v];
		if(!IOI)e[++mm]=e1[i];
		IOI=g[e1[i].v][e1[i].u]=e1[i].w;
	}
	sort(e+1,e+mm+1,cmp);
	for(i=1;i<=n;++i)par[i]=i;
	for(i=1;i<=mm;++i){
		u=e[i].u,v=e[i].v,fu=fi(u),fv=fi(v);
		if(fu==fv)continue;
		par[fu]=fv,ff=fa[u],qq=u;
		while(ff)
			swap(fa[ff],qq),swap(ff,qq);			
		fa[u]=v;
	}
	for(i=Q;i;--i){
		u = mo[i].u,v=mo[i].v,now=u,rec[now]=0;
		while(now){sign[now]=i,rec[fa[now]]=max(rec[now],g[now][fa[now]]),now=fa[now];}
		LCA=v,ans=0,ANS=0;
		while(LCA&&sign[LCA]!=i){ans=max(ans,g[LCA][fa[LCA]]),LCA=fa[LCA];}
		ANS=max(ans,rec[LCA]);
		if(mo[i].k==1){anss[++cnt]=ANS;}
		else {
			if(ANS<=g[u][v])continue;
			if(ans>rec[LCA])swap(u,v);
			ff=fa[u],qq=u;
			while(g[qq][ff]!=ANS){
				swap(fa[ff],qq),swap(ff,qq);
			}
			fa[u]=v;
		}
				
	}
	for(i=cnt;i;--i)write(anss[i]),puts("");
	return 0;	
}