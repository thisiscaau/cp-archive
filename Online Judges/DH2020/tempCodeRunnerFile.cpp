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
    if (a.fi < b.fi) return true;
    else if (a.fi > b.fi) return false;
    return a.se < b.se;
}
priority_queue<ll,vector<ll>,greater<ll>> pq;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) pq.push(i);
    while (!pq.empty()){
        ll a = pq.top(); pq.pop();
        cout << a << endl;
    }
}