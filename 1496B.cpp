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
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll k,n,t;
string s;
/* workspace */
bool check(string s){
    string a = s.substr(0,k) + s.substr(n-k,k);
    string b = a;
    reverse(b.begin(),b.end());
    if (a == b) return true;
    else return false;
}
void solve(){
    cin >> n >> k;
    cin >> s;
    if (k == 0){
        cout << "YES" << endl;
    }
    else if (k*2==n){
        cout << "NO" << endl;
    }
    else if (check(s)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--){
        solve();
    }
}