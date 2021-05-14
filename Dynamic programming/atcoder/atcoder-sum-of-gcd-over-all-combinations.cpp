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
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;
ll tc,n,k;

ll binpow (ll a,ll b){
    a %= mod; ll res = 1;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    cin >> n >> k;
    ll dp[k + 1];
    memset(dp,0,sizeof(dp));
    ll tot = 0;
    // dp[i] the number of ways to form an array of size n with gcd i
    for (int i = k ; i >= 1 ; i--){
        dp[i] = binpow(k / i,n);
        for (int j = 2 * i ; j <= k ; j += i) dp[i] -= dp[j];
        tot = (tot + dp[i]*i) % mod;
    }
    cout << (tot + mod) % mod << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--){
        solve();
    }
}