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
ll a[MAXN];
ii pre[MAXN];
priority_queue<ll> pq;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        a[i] -= m;
    }
    for (int i = 1 ; i <= n ; i++){
        pre[i].fi = pre[i-1].fi + a[i];
        pre[i].se = i;
    }
    sort(pre,pre+n+1);
    ll cur = n-1, ans = 0;
    while (cur >= 0){
        // fixing left
        pq.push(pre[cur+1].se);
        ll idx = pq.top();
        ans = max(ans,idx-pre[cur].se);
        cur--;
    }
    cout << ans;
}