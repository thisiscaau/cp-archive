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
ll a[MAXN];
ll pre[MAXN];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("manin.txt","r",stdin);
    freopen("manout.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    ll ans = 0;
    for (int i = m ; i <= n ; i++){
        ans = max(ans,pre[i] - pre[i-m]);
    }
    cout << ans;
    return 0;
}