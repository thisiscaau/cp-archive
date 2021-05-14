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
ll cnt[5];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("flowin.txt","r",stdin);
    freopen("flowout.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll x,y; cin >> x >> y;
        if (x <= n && y <= n) cnt[1]++;
        else if (x > n && y <= n) cnt[2]++;
        else if (x <= n && y > n) cnt[3]++;
        else cnt[4]++;
    }
    ll mx = max({cnt[1],cnt[2],cnt[3],cnt[4]});
    for (int i = 1 ; i <= 4 ; i++){
        if (cnt[i] == mx){
            cout << i << " " << cnt[i];
            return 0;
        }
    }
}