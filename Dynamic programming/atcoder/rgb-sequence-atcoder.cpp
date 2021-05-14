/*
thisiscaau's code
trying my best for a better future
*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll const mod = 1e9 + 7, MAXN = 2e5 + 5;
ll n,m;
vector<pair<ll,ll>> quest[301];

ll dp[301][301][301];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll l,r,x; cin >> l >> r >> x;
        quest[r].pb(mp(l,x));
    }
    // dp[i][j][k] number of ways to color
    // given three last pos
    // i - current index - j,k other two last pos
    dp[1][0][0] = 3; // -> forward transition
    for (int i = 1 ; i <= n - 1 ; i++){
        for (int j = 0 ; j <= i ; j++){
            for (int k = 0 ; k <= j ; k++){
                if (!dp[i][j][k]) continue;
                for (pair<ll,ll> con : quest[i]){
                    if (con.se == 1 && con.fi <= j){
                        dp[i][j][k] = 0;
                        break;
                    }
                    if (con.se == 2 && (con.fi <= k || con.fi > j)){
                        dp[i][j][k] = 0;
                        break;
                    }
                    if (con.se == 3 && con.fi > k){
                        dp[i][j][k] = 0;
                        break;
                    }
                }
                if (!dp[i][j][k]) continue;
                // transit
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % mod;
                dp[i+1][i][j] = (dp[i+1][i][j] + dp[i][j][k]) % mod;
                dp[i+1][i][k] = (dp[i+1][i][k] + dp[i][j][k]) % mod;
            }
        }
    }
    ll tot = 0;
    for (int j = 0 ; j <= n ; j++){
        for (int k = 0 ; k <= j ; k++){
            if (!dp[n][j][k]) continue;
            for (pair<ll,ll> con : quest[n]){
                if (con.se == 1 && con.fi <= j){
                    dp[n][j][k] = 0;
                    break;
                }
                if (con.se == 2 && (con.fi <= k || con.fi > j)){
                    dp[n][j][k] = 0;
                    break;
                }
                if (con.se == 3 && con.fi > k){
                    dp[n][j][k] = 0;
                    break;
                }
            }
            if (!dp[n][j][k]) continue;
            tot = (tot + dp[n][j][k]) % mod;
        }
    }
    cout << tot;
}