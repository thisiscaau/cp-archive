/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed
 
/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long
 
#define sz(a) (int)a.size()
#define pii pair<int,int>
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6
 
using namespace std;
 
vector<pii> g[500005];
int n, m, d[500005];
map<pii, int> mp;
 
signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    // freopen("cf.inp", "r", stdin);
    // freopen("cf.out", "w", stdout);
 
    cin >> n >> m;
    int cnt = n;
 
    for1(i,1,m) {
        int a, b, w, na, nb;
        cin >> a >> b >> w;
 
        if (mp[{a, w}]) na = mp[{a, w}];
        else na = mp[{a, w}] = ++cnt;
 
        if (mp[{b, w}]) nb = mp[{b, w}];
        else nb = mp[{b, w}] = ++cnt;
 
        g[na].push_back({nb, 0});
        g[nb].push_back({na, 0});
 
        g[na].push_back({a, 1});
        g[a].push_back({na, 0});
        g[nb].push_back({b, 1});
        g[b].push_back({nb, 0});
 
    }
 
    for1(i,2,cnt) d[i] = INF;
    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
 
    pq.push({0, 1});
 
    while (!pq.empty()) {
 
        int d_u = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d_u != d[u]) continue;
 
        for (auto e : g[u]) {
            int v = e.first, w = e.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
 
    }
 
    if (d[n] == INF) cout << -1;
    else cout << d[n];
 
}
// kekw