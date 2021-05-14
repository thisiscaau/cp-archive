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
ll const mod = 998244353, MAXN = 3e5 + 5;
/* declaration */
ll n,m,tc;
ll dp[MAXN];
ll pw[MAXN];
/* workspace */
void init(){
    pw[0] = 1;
    for (int i = 1 ; i < MAXN ; i++){
        pw[i] = (pw[i-1] * 2) % mod;
    }
    dp[0] = dp[1] = 0; dp[2] = 1;
    for (int i = 3 ; i < MAXN ; i++){
        dp[i] = dp[i-1] + 2*dp[i-2] + pw[i-2];
        dp[i] %= mod;
    }
}
ll wh,ans;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    bool mat[n+5][m+5];
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            char a; cin >> a;
            mat[i][j] = (a == 'o');
            if (mat[i][j]) wh++;
        } 
    }
    for (int i = 1 ; i <= n ; i++){
        ll cnt = 0;
        for (int j = 1 ; j <= m + 1 ; j++){
            if (mat[i][j]) cnt++;
            else {
                ans += dp[cnt]*pw[wh-cnt];
                ans %= mod;
                cnt = 0;
            }
        }
    }
    for (int i = 1 ; i <= m ; i++){
        ll cnt = 0;
        for (int j = 1 ; j <= n + 1; j++){
            if (mat[j][i]) cnt++;
            else {
                ans += dp[cnt]*pw[wh-cnt];
                ans %= mod;
                cnt = 0;
            }
        }
    }
    cout << ans;
}