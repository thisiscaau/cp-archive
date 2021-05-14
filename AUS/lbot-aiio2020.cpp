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
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
vector<ll> tmp;
ll mat[1005][1005];
ll dp[1005];
/* workspace */
ll cal(){
    memset(dp,0,sizeof(dp));
    for (int i = 1 ; i < tmp.size() ; i++){
        // pos
        dp[i] = dp[i-1];
        if (i == 1) dp[i] = max(0ll,tmp[i]+tmp[i-1]);
        else dp[i] = max(dp[i],dp[i-2] + max(0ll,tmp[i] + tmp[i-1]));
    }
    return dp[tmp.size()-1];
}
ll tot = 0;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> mat[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++){
        // dp in rows
        tmp.clear();
        for (int j = 1 ; j <= m ; j++){
            tmp.pb(mat[i][j]);
        }
        tot += cal();
    }
    for (int i = 1 ; i <= m ; i++){
        // dp in col
        tmp.clear();
        for (int j = 1 ; j <= n ; j++){
            tmp.pb(mat[j][i]);
        }
        tot += cal();
    }
    cout << tot;
}