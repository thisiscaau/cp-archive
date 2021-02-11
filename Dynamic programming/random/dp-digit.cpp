/* Do what u love, love what u do */
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)
long double pi = 3.14159265359;
vector<ll> dig;
ll dp[20][2][2520][(1<<9)+5];
ll cal(ll idx,ll tight,ll rem,ll mask){
    ll &res = dp[idx][tight][rem][mask];
    if (res!=-1){
        return res;
    }
    res = 0;
    if (idx==dig.size()){
        bool ok = true;
        For(i,1,10){
            if (mask & (1 << (i-1))){
                if (rem % i != 0){
                    ok = false;
                    break;
                }
            }
        }
        if (ok){
            res = 1;
        }
    }
    else {
        ForE(d,0,10){
            if (tight & (d>dig[idx])) continue;
            ll ntight = ((tight == 1) ? (d == dig[idx]) : 0);
            ll nrem = (rem*10+d) % 2520;
            ll nmask = mask;
            if (d!=0){
                nmask = mask | (1 << (d-1));
            }
            res += cal(idx+1,ntight,nrem,nmask);
        }
    }
    return res;
}
ll solve(ll n){
    dig.clear();
    if (n==0) dig.pb(n);
    while(n){
        dig.pb(n%10);
        n /= 10;
    }
    reverse(dig.begin(),dig.end());
    memset(dp,-1,sizeof(dp));
    return cal(0,1,0,0);
}
ll t;
signed main(){
    //freopen("16.inp","r",stdin);
    //freopen("16.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        ll ans = solve(r) - solve(l-1);
        cout << ans << endl;
    }
}