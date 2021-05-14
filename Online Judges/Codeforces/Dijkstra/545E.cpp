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
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,src;
/* workspace */
struct edge {
    ll node,w,id;
    edge() {}
    edge(ll a,ll b,ll c) : node(a),w(b),id(c) {}
};
vector<edge> g[MAXN];
ll last[MAXN],id[MAXN],d[MAXN];
priority_queue<ii,vii,greater<ii>> pq;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb(edge(v,w,i));
        g[v].pb(edge(u,w,i));
    }
    cin >> src;
    memset(d,inf,sizeof(d));
    memset(last,inf,sizeof(last));
    d[src] = 0; last[src] = 0;
    pq.push(mp(0,src)); id[src] = -1;
    while (!pq.empty()){
        ii cur = pq.top(); pq.pop();
        if (d[cur.se] != cur.fi) continue;
        for (auto nxt : g[cur.se]){
            if (cur.fi + nxt.w < d[nxt.node]){
                d[nxt.node] = cur.fi + nxt.w;
                last[nxt.node] = nxt.w;
                id[nxt.node] = nxt.id;
                pq.push(mp(d[nxt.node],nxt.node));
            }
            else if (cur.fi + nxt.w == d[nxt.node] && nxt.w < last[nxt.node]){
                last[nxt.node] = nxt.w;
                id[nxt.node] = nxt.id;
            }
        }
    }
    ll tot = 0;
    for (int i = 1 ; i <= n ; i++) tot += last[i];
    cout << tot << endl;
    for (int i = 1 ; i <= n ; i++) {
        if (id[i] != -1){
            cout << id[i] << " ";
        }
    }
}