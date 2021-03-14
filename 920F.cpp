/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
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
ll const inf = 1e9 + 7, MAXN = 3e5 + 5,N = 1e6 + 5;
/* declaration */
ll n,m;
ll A[MAXN];
ll d[N];
ll lp[N];
vector<ll> pr;
ll sum[4*MAXN],mx[4*MAXN]; // segment tree stuffs
/* workspace */
void sieve(){
    for (int i = 2 ; i <= N ; i++){
        if (lp[i] == 0){
            lp[i] = i;
            pr.pb(i);
        }
         for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    d[1] = 1;
    for (int i = 2; i <= N ; i++){
        ll cur = i; ll cnt = 1;
        while (cur != 1){
            ll prime = lp[cur]; ll pw = 0;
            while (cur % prime == 0){
                pw++;
                cur /= prime;
            }
            cnt *= (pw+1);
        }
        d[i] = cnt;
    }
}
void build(ll idx,ll l,ll r){
    if (l == r){
        sum[idx] = A[l];
        mx[idx] = A[l];
    }
    ll m = (l+r)/2;
    build(idx*2,l,m);
    build(idx*2+1,m+1,r);
    sum[idx] = sum[idx*2] + sum[idx*2+1];
    mx[idx] = max(mx[idx*2],mx[idx*2+1]);
}
void upd(ll idx,ll l,ll r,ll tl,ll tr){
    if (l > tr || r < tl || mx[idx] <= 2) return;
    if (l == r){
        A[l] = d[A[l]];
        sum[idx] = A[l]; mx[idx] = A[l];
        return;
    }
    ll m = (l+r)/2;
    upd(idx*2,l,m,tl,tr);
    upd(idx*2+1,m+1,r,tl,tr);
    sum[idx] = sum[idx*2] + sum[idx*2+1];
    mx[idx] = max(mx[idx*2],mx[idx*2+1]);
}
ll query(ll idx,ll l,ll r,ll tl,ll tr){
    if (l > tr || r < tl) return 0;
    if (l >= tl && r <= tr) return sum[idx];
    ll m = (l+r)/2;
    return query(idx*2,l,m,tl,tr) + query(idx*2+1,m+1,r,tl,tr);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];        
    }
    sieve();
    build(1,1,n);
    for (int i = 1 ; i <= m ; i++){
        ll op,l,r;
        cin >> op >> l >> r;
        if (op == 1) upd(1,1,n,l,r);
        else cout << query(1,1,n,l,r) << endl;
    }
}