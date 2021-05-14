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
ll a,b,c,posa,posb,posc;
string exp;
string a_,b_,c_;
ll dp[25][25][25][2];
string fia[25][25][25][2],fib[25][25][25][2];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> exp;
    stringstream inp(exp); char ch;
    exp >> a >> ch >> b >> ch >> c;
    memset(dp,inf,sizeof(dp));
    a_ = to_string(a); b_ = to_string(b); c_ = to_string(c);
    a_ = '0' + a_; b_ = '0' + b_; c_ = '0' + c_;
    // starting from digit col
    posa = a_.size() - 1; posb = b_.size() - 1; posc = c_.size() - 1;
    dp[posa][posb][posc][0] = 0;
    solve(posa,posb,posc,0);
    cout << fia[0][0][0][0] << "+" << fib[0][0][0][0] << "=" << stoll(fia[0][0][0][0]) + stoll(fib[0][0][0][0]);
}