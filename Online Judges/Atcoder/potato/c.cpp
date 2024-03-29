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
/* workspace */
ll a[MAXN];
ll lf[MAXN],rt[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    stack<ll> st;
    for (int i = 1 ; i <= n ; i++){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) lf[i] = -1;
        else lf[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n ; i >= 1 ; i--){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) rt[i] = -1;
        else rt[i] = st.top();
        st.push(i);
    }
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++){
        ll l,r;
        r = (rt[i] == -1) ? n - i + 1 : rt[i] - i;
        l = (lf[i] == -1) ? i : i - lf[i];
        //cout << a[i] << " " << l << " " << r << endl;
        ans += a[i]*l*r;
    }
    cout << ans;
}