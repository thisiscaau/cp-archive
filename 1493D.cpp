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
ll const inf = 1e9 + 7, MAXN = 1e6 + 5;
/* declaration */
string ori,tar;
ll n;
map<string,ll> d;
map<string,bool> vis;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a;
        char dig = '0' + a;
        ori += dig;
    }
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a;
        char dig = '0' + a;
        tar += dig;
    }
    d[ori] = 0;
    queue<string> q;
    q.push(ori); vis[ori] = true;
    while (!q.empty()){
        string cur = q.front(); q.pop();
        for (int l = 1 ; l < n ; l++){
            for (int r = l; r < n ; r++){
                string seg = cur.substr(l,r-l+1);
                string str = seg + cur.substr(0,l);
                if (r+1 < n){
                    str += cur.substr(r+1,n-1-r);
                }
                if (!vis[str]){
                    vis[str] = true;
                    d[str] = d[cur] + 1;
                    q.push(str);
                    if (str == tar) break;
                }
            }
        }
    }
    cout << d[tar];
}