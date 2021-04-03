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
#define pf push_front
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,g,tc;
ll mat[505][505];
ll dp[505][505];
/* workspace */
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};
deque<ii> q;
bool check(ll i,ll j){
    return (i >= 1 && i <= n && j >= 1 && j <= n);
}
void solve1(){
    memset(dp,-1,sizeof(dp));
    q.pb(mp(1,1)); dp[1][1] = 0;
    while (!q.empty()){
        ii cur = q.front(); q.pop_front();
        ll i = cur.fi , j = cur.se;
        for (int go = 0 ; go < 4 ; go++){
            ll ni = i + dx[go], nj = j + dy[go];
            if (check(ni,nj) && dp[ni][nj] == -1){
                if (mat[ni][nj] < g){
                    // unsafe
                    dp[ni][nj] = dp[i][j] + 1;
                    q.pb(mp(ni,nj)); 
                }
                else {
                    // safe
                    dp[ni][nj] = dp[i][j];
                    q.pf(mp(ni,nj));
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}
bool test(ll w){
    memset(dp,-1,sizeof(dp));
    q.pb(mp(1,1));
    dp[1][1] = 0;
    while (!q.empty()){
        ii cur = q.front(); q.pop_front();
        ll i = cur.fi , j = cur.se;
        for (int go = 0 ; go < 4 ; go++){
            ll ni = i + dx[go], nj = j + dy[go];
            if (check(ni,nj) && dp[ni][nj] == -1){
                if (mat[ni][nj] >= w){
                    dp[ni][nj] = dp[i][j] + 1;
                    q.pb(mp(ni,nj));
                }
            }
        }
    }
    return (dp[n][n] != -1);
}
void solve2(){
    ll l = 1 , r = 10000;
    ll res = 0;
    while (l <= r){
        ll mid = (l+r) >> 1;
        if (test(mid)){
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin >> tc;
    cin >> n;
    if (tc == 1) cin >> g;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            cin >> mat[i][j];
        }
    }
    if (tc == 1){
        solve1();
    }
    else {
        solve2();
    }
}