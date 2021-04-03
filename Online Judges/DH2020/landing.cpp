/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
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
ll n,k,x;
vector<ii> plane;
/* workspace */
bool comp(ii a,ii b){
    return a.fi < b.fi;
}
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll res = 0;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("LANDING.inp","r",stdin);
    freopen("LANDING.out","w",stdout);
    cin >> n >> k >> x;
    for (int i = 1 ; i <= k ; i++) pq.push(-x);
    for (int i = 1 ; i <= n ; i++){
        ii a; cin >> a.fi >> a.se;
        plane.pb(a);
    }
    sort(plane.begin(),plane.end(),comp);
    for (int i = 0 ; i < n ; i++){
        ll port = pq.top();
        if (port + x <= plane[i].se){
            pq.pop();
            res++;
            pq.push(max(port+x,plane[i].fi));
        }
    }
    cout << res << " ";
    ll l = x , r = inf;
    while (l < r){
        ll mid = (l+r+1) >> 1, cnt = 0;
        priority_queue<ll,vector<ll>,greater<ll>> pq2;
        for (int i = 1 ; i <= k ; i++) pq2.push(-mid);
        for (int i = 0 ; i < n ; i++){
            ll port = pq2.top();
            if (port + mid <= plane[i].se){
                pq2.pop();
                cnt++;
                pq2.push(max(port+mid,plane[i].fi));
            }
        }
        if (cnt == res){
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << (l == inf ? -1 : l);
}