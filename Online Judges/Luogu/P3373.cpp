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
#define FOR(i,a,b) for (int i = a ; i <= b ; i++)
#define FORD(i,a,b) for (int i = a ; i >= b ;i--)
#define left node << 1,tl,tm
#define right node << 1 | 1,tm+1,tr
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;
ll n,m,p;
ll a[MAXN],st[MAXN << 2],add[MAXN << 2],mul[MAXN << 2];


void build (ll node = 1,ll tl = 1,ll tr = n){
    add[node] = 0; mul[node] = 1;
    if (tl == tr){
        st[node] = a[tl];
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(left); build(right);
    st[node] = (st[node << 1] + st[node << 1 | 1]) % p;
}


void apply(ll node, ll len){
    // lazy update
    // len = size of segment of node
    ll lf = len - (len >> 1), rt = len >> 1; // divide
    if (mul[node] != 1){
        (add[node << 1] *= mul[node]) %= p , (add[node << 1 | 1] *= mul[node]) %= p;
        (st[node << 1] *= mul[node]) %= p , (st[node << 1 | 1] *= mul[node]) %= p;
        (mul[node << 1] *= mul[node]) %= p , (mul[node << 1 | 1] *= mul[node]) %= p;
        mul[node] = 1;
    }
    if (add[node] != 0){
        (add[node << 1] += add[node]) %= p , (add[node << 1 | 1] += add[node]) %= p;
        (st[node << 1] += lf*add[node] % p) %= p, (st[node << 1 | 1] += rt*add[node] % p) % p;
        add[node] = 0;
    }
}

ll get(ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (l > tr || r < tl || l > r) return 0;
    if (l <= tl && tr <= r) return st[node];
    apply(node,tr-tl+1);
    ll tm = (tl+tr) >> 1;
    return (get(l,r,left) + get(l,r,right)) % p;
}

void update (ll type,ll val,ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (l > r || tl > tr || l > tr || r < tl) return;
    if (l <= tl && tr <= r){
        if (type == 1){
            st[node] = (st[node] * val) % p;
            add[node] = (add[node] * val) % p;
            mul[node] = (mul[node] * val) % p;
        }
        else {
            st[node] = (st[node] + val*(tr - tl + 1) ) % p;
            add[node] = (add[node] + val) % p;
        }
        return;
    }
    apply(node,tr - tl + 1);
    ll tm = (tl + tr) >> 1;
    update(type,val,l,r,left); update(type,val,l,r,right);
    st[node] = (st[node << 1] + st[node << 1 | 1]) % p;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> p;
    FOR(i,1,n){
        cin >> a[i];
        a[i] %= p;
    }
    build();
    FOR(i,1,m){
        ll opt; cin >> opt;
        if (opt == 3){
            ll l,r; cin >> l >> r;
            cout << get(l,r) << endl;
        }
        else {
            ll x,y,k; cin >> x >> y >> k;
            update(opt,k,x,y);
        }
    }
}


/* 
1 x y k mul range by k
2 x y k add range by k
3 x y output sum range
*/