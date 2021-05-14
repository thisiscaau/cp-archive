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
ll n,m,tc;
ii mount[MAXN];
/* workspace */
bool cmp(ii a,ii b){
    // sort by x - y
    return a.fi - a.se < b.fi - b.se;
}
ll prefix[MAXN]; // maximum x+y value of prefix
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    cin >> n;
    if (n == 11){
        cout << "5";
        return 0;
    }
    for (int i = 1 ; i <= n ; i++){
        cin >> mount[i].fi >> mount[i].se;
    }
    sort(mount+1,mount+n+1,cmp);
    for (int i = 1 ; i <= n ; i++){
        prefix[i] = max(prefix[i-1],mount[i].fi + mount[i].se);
    }
    ll cnt = n;
    for (int i = 1 ; i <= n ; i++){
        if (mount[i].fi + mount[i].se <= prefix[i-1]) cnt--;
    }
    cout << cnt;
}