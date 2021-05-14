/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define double float
#define se second
#define pb push_back
#define other cu
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
double const inf = 100000000*1.0000;
/* declaration */
ll n,m,tc;
double d[55][55];
/* workspace */
struct edge {
    ll cnt,node;
    double w;
    bool operator > (edge const& other) const {
        return w > other.w;
    }
};
vii g[55];
priority_queue<edge,vector<edge>,greater<edge>> pq;
double dijkstra (ll st){
    d[st][0] = 0;
    for (int i = 1 ; i <= n ; i++) d[st][i] = inf;
    edge ori; ori.node = st; ori.cnt = 0; ori.w = 0;
    pq.push(ori);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (cur.w != d[cur.node][cur.cnt]) continue;
        for (ii nxt : g[cur.node]){
            double edge_w = (nxt.fi*1.00) / ((cur.cnt+1) * 1.00);
            double nw = edge_w + cur.w;
            if (nw < d[nxt.se][cur.cnt + 1]){
                d[nxt.se][cur.cnt+1] = nw;
                edge upd; upd.cnt = cur.cnt + 1; upd.node = nxt.se; upd.w = nw;
                pq.push(upd);
            }
        }
    }
    double ans = inf;
    for (int i = 2 ; i <= n ; i++){
        ans = min(ans,d[st][i]);
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v,w; cin >> u >> v >> w;
        g[u].pb(mp(w,v));
    }
    double ans = inf;
    for (int i = 1 ; i <= n ; i++){
        ans = min(ans,dijkstra(i));
    }
    if (ans >= inf) cout << "-1";
    else cout << fixed << setprecision(4) << ans;
}