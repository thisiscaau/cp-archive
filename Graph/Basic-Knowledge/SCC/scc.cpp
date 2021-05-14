/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* 
Graph Theory :
Strongly Connected Components Finding
Components in which any 2 nodes can go to each other
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
ll n,m,timer,scc;
ll tin[MAXN],low[MAXN],sc[MAXN];
vector<ll> g[MAXN];
stack<ll> st;
/* workspace */

void tarjan (ll u,ll p = -1){
    tin[u] = low[u] = ++timer;
    st.push(u);
    for (ll v : g[u]){
        if (v == p) continue;
        if (tin[v] == 0){
            // unvisited
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else {
            // back edge
            low[u] = min(low[u],tin[v]);
        }
    }
    if (low[u] == tin[u]){
        scc++;
        while (1){
            ll v = st.top(); st.pop();
            sc[V] = scc;
            // DO SOMETHING WITH THIS SCC HERE
            if (v == u) break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        g[u].pb(v);
    }
    for (int i = 1 ; i <= n ; i++){
        if (tin[i] == 0) tarjan(i);
    }
}