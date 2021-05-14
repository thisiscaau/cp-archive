/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
ll n,m,timer;
ll vis[MAXN];
ll tin[MAXN],low[MAXN],deg[MAXN];
vector<ll> g[MAXN];

void testcase(){
    for (int i = 1 ; i <= n ; i++){
        g[i].clear();
        vis[i] = 0;
        deg[i] = 0;
        low[i] = 0;
        tin[i] = 0;
    }
}

void tarjan(ll u,ll par){
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for (ll v : g[u]){
        if (v == par) continue;
        if (vis[v] == 1){
            // back-edge
            low[u] = min(low[u],tin[v]);
        }
        else if (vis[v] == 0){
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
    }
    vis[u] = true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while (cin >> n >> m){
        testcase();
        for (int i = 1 ; i <= m ; i++){
            ll u,v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        timer = 0; tarjan(1,-1);
        ll pendant = 0;
        for (int u = 1 ; u <= n ; u++){
            for (ll v : g[u]){
                if (low[u] != low[v]){
                    deg[low[u]]++;
                }
            }
        }
        for (int i = 1 ; i <= n ; i++){
            if (deg[i] == 1) pendant++;
        }
        cout << (pendant+1) / 2 << endl;
    }
}