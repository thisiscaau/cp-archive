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
ll n,m,tc;
struct edge{
    ll u,w;
    bool operator > (const edge& other) const{
        return w > other.w;
    }
};
priority_queue<edge,vector<edge>,greater<edge>> pq;
vector<ii> g[MAXN];
bool vis[MAXN];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll cur,cnt;
        cin >> cur >> cnt;
        for (int j = 1 ; j <= cnt ; j++){
            ll dest; cin >> dest;
            g[dest].pb(mp(n+i,cur)); // connect with hypergrid
            g[n+i].pb(mp(dest,0));
        }
    }
    edge ori; ori.u = 1; ori.w = 0;
    pq.push(ori);
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (vis[cur.u]) continue;
        if (cur.u == n){
            cout << cur.w ;
            return 0;
        }
        for (ii e : g[cur.u]){
            edge go; go.u = e.fi; go.w = cur.w + e.se;
            pq.push(go);
        }
        vis[cur.u] = true;
    }
}