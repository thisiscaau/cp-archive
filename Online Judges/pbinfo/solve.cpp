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
ll const mod = 20173333, MAXN = 1e5 + 5;
/* declaration */
ll n,m,tc;
/* workspace */
ll fact[MAXN];
ll invFact[MAXN];
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}
void process(){
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
}
ll dp[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("COUNT.inp","r",stdin);
    //freopen("COUNT.out","w",stdout);
    cin >> tc;
    cin >> n >> m;
    if (tc == 1){
        process();
        cout << C(n-1,m-1) << endl;
    }
    else{
        dp[1] = dp[2] = 1;
        for (int i = 3 ; i <= n+1 ; i++){
            dp[i] = 2*dp[i-1] - dp[max(i-m-1,0ll)];
            if (dp[i] > mod) dp[i] -= mod;
        }
        cout << dp[n+1];
    }
}