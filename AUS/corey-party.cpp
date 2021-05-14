#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
typedef pair<double, double> ii;
set<int> adj[1003];
int degree[1003];
int valid[1003];
int N, A, B, M;
 
void eliminate(int u){
  
    for(auto c : adj[u]){
        degree[c]--;
        adj[c].erase(u);
    }
    adj[u].clear();
    degree[u]=0;
}
 
int main(){
    freopen("partyin.txt","r",stdin);
    freopen("partyout.txt","w",stdout);
cin >> N >> M >> A >> B;
int b = N-B-1;
int x, y;
for(int i = 0; i < M; i++){
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
}
for(int i = 1; i <= N; i++){
    degree[i]=adj[i].size();
}
 
for(int i = 0; i < 1001; i++)valid[i]=1;
for(int j = 1; j <= N; j++){
for(int i = 1; i <= N; i++){
    if(valid[i] && (degree[i]<A||degree[i]>b)){
        b--;
        valid[i]=0;
        eliminate(i);
    }
}
}
int ans = 0;
for(int i = 1; i <= N; i++){
    if(degree[i]>0)ans++;
}
cout << ans << endl;
return 0;
}