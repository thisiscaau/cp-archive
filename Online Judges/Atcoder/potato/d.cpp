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
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,m,tc;
/* workspace */
vector<ii> g[MAXN];
struct edge {
    ll node,last,fare;
    bool operator > (const edge& other) const {
        return fare > other.fare;
    }
};
ll d[MAXN];
priority_queue<edge,vector<edge>,greater<edge>> pq;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v,s;
        cin >> u >> v >> s;
        g[u].pb(mp(v,s));
        g[v].pb(mp(u,s));
    }
    memset(d,inf,sizeof(d));
    d[1] = 0;
    edge ori; ori.node = 1; ori.fare = 0; ori.last = 0;
    pq.push(ori);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (d[cur.node] != cur.fare) continue;
        for (ii nxt : g[cur.node]){
            edge upd;
            upd.last = (cur.last != nxt.se) ? nxt.se : cur.last;
            upd.fare = (cur.last != nxt.se) ? cur.fare + 1 : cur.fare;
            upd.node = nxt.fi;
            if (upd.fare < d[upd.node]){
                d[upd.node] = upd.fare;
                pq.push(upd);
            }
        }
    }
    if (d[n] >= inf) cout << "-1";
    else cout << d[n];
}