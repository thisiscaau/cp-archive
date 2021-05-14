#include<bits/stdc++.h>
using namespace std;
vector<long long> a[1001],res,tham[1001];
long long v[100001];
long long n,m,k;
void bfs(long long u){
	deque <long long> dq;
	res[u]=0;
	dq.push_back(u);
    tham[u].resize(n);
	while(!dq.empty()){
		long long u=dq.front();
		tham[n][u]=1;
		dq.pop_front();
		for(long long i=0;i<a[u].size();i++){
			if(tham[n][a[u][i]]==0&&res[u]+1<res[a[u][i]]){
				res[a[u][i]]=res[u]+1;
				dq.push_back(a[u][i]);
				tham[n][a[u][i]]=1;
			}
		}
	}
}
int main (){
	cin>>n>>k;
	for(long long i=1;i<=k;i++) cin>>v[i];
	cin>>m;
	for(long long i=1;i<=m;i++){
		long long x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(long long i=1;i<=k;i++){
		bfs(v[i]);
	}
	for(long long i=1;i<=n;i++){
		cout<<res[i]<<" ";
	}
}