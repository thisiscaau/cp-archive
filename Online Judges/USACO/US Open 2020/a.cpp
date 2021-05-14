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
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m;
vector<ll> vi;
bool check(ll cite){
    vector<ll>::iterator lw = lower_bound(vi.begin(),vi.end(),cite);
    if (lw == vi.end()) return false;
    ll cnt = vi.end() - lw;
    if (cnt >= cite) return true;
    ll left = m;
    for (int i = lw - vi.begin() - 1 ; i >= 0 ; i--){
        if (left == 0) break;
        if (vi[i] + 1 < cite) return false;
        else cnt++, left--; 
    }
    if (cnt >= cite) return true;
    return false;
}
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        ll w; cin >> w;
        vi.pb(w);
    }
    sort(vi.begin(),vi.end());
    ll l = 1 , r = 1e5 + 5;
    while (l < r){
        ll mid = (l+r+1) >> 1;
        if (check(mid)){
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    cout << l;
}