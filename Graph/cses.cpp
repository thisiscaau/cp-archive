#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll const MAXN = 1e5 + 5;
vector<ll> back_edge[MAXN];
ll out_degree[MAXN];
vector<ll> ans;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll a,b;
        cin >> a >> b;
        out_degree[a]++;
        back_edge[b].pb(a);
    }
    priority_queue<ll> pq;
    for (int i = 1 ; i <= n ; i++){
        if (!out_degree[i]) pq.push(i);
    }
    while (!pq.empty()){
        ll v = pq.top();
        pq.pop();
        ans.pb(v);
        for (auto u : back_edge[v]){
            out_degree[u]--;
            if (out_degree[u]==0) pq.push(u);
        }
    }
    reverse(ans.begin(),ans.end());
    for (auto v : ans){
        cout << v << " ";
    }
}