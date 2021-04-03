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
ll n,opt,idx;
/* workspace */
/* operation 1 */
string str,res;
bool cmp(string a,string b){
    // check if b smaller than a
    ll idx = 0,sz = a.size();
    while (idx < sz){
        if (a[idx] > b[idx]) return true;
        else if (b[idx] > a[idx]) return false;
        idx++;
    }
    return true;
}
void solve1(){
    cin >> n; ll mx = 0;
    while (getline(cin,str)){
        ll len = str.size();
        if (len > mx){
            mx = len;
            res = str;
        }
        else if (len == mx && cmp(res,str)){
            res = str;
        }
    }
    cout << res << endl;
}
/* operation 2 */
bool vis[205];
bool check(string a,string b){
    ll x = a.size() , y = b.size();
    ll i = 0 , j = 0;
    while (i < x && j < y){
        if (a[i] == b[j]){
            j++;
        }
        i++;
        if (i == x && j < y) return false;
    }
    if (j == y) return true;
    return false; 
}
string a[205];
void solve2(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        for (int j = 1 ; j < i ; j++){
            if (!vis[j]){
                if (a[i].size() >= a[j].size()){
                    if (check(a[i],a[j])) vis[j] = 1;
                }
                else {
                    if (check(a[j],a[i])) vis[i] = 1;
                }
            }
        }
    }
    ll cnt = 0;
    for (int i = 1 ; i <= n ; i++){
        if (!vis[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1 ; i <= n ; i++){
        cout << a[i] << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("interesant.in","r",stdin);
    freopen("interesant.out","w",stdout);
    cin >> opt;
    if (opt == 1){
        solve1();
    }
    else solve2();
}