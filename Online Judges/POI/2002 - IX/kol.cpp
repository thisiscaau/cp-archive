/*
thisiscaau's code
trying my best for a better future
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define left node << 1,tl,tm
#define right node << 1 | 1,tm + 1,tr
#define FOR(i,a,b) for (int i = a ; i <= b ; i++)
#define FORD(i,a,b) for (int i = a ; i >= b ;i--)
ll const inf = 1e9 + 7, MAXN = 60000,oo = 3e18;
ll c,s,r;
ll st[MAXN << 2]; 
// segment tree - find maximum number of guest in given timeline
ll lz[MAXN << 2];

void apply(ll node){
    if (lz[node] == 0) return;
    st[node << 1] += lz[node];
    lz[node << 1] += lz[node];
    st[node << 1 | 1] += lz[node];
    lz[node << 1 | 1] += lz[node];
    lz[node] = 0;
}

void update(ll l,ll r,ll val,ll node = 1,ll tl = 1,ll tr = c - 1){
    if (l > r || tl > r || tr < l) return;
    if (l <= tl && tr <= r){
        st[node] += val;
        lz[node] += val;
        return;
    }
    apply(node);
    ll tm = (tl + tr) >> 1;
    update(l,r,val,left); update(l,r,val,right);
    st[node] = max(st[node << 1],st[node << 1 | 1]);
}

ll query (ll l,ll r,ll node = 1,ll tl = 1,ll tr = c - 1){
    if (l > r || r < tl || l > tr) return -inf;
    if (l <= tl && tr <= r){
        return st[node];
    }
    apply(node);
    ll tm = (tl + tr) >> 1;
    return max(query(l,r,left) , query(l,r,right));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> s >> r;
    while (r--){
        ll from,to,seat;
        cin >> from >> to >> seat;
        if (query(from,to-1) + seat <= s){
            cout << "T" << endl;
            update(from,to-1,seat);
        }
        else {
            cout << "N" << endl;
        }
    }
}