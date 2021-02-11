#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1e5 + 1;
vector<ll> adj[MAXN];
ll side[MAXN];
queue<ll> q;
bool is_bipartite = true;
signed main(){
    ll n,m;
    memset(adj,-1,sizeof(adj));
    cin >> n >> m;
    while (m--){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1 ; i <= n ; i++){
        if (side[i]==-1){
            q.push(i);
            side[i] = 0;
            while (!q.empty()){
                ll v = q.front();
                q.pop();
                for (auto u : adj[v]){
                    if (side[u]==-1){
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if (is_bipartite){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}