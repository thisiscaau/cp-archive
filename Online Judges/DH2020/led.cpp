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
ll opt;
string num;
/* workspace */
ll dig[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
ll eq[20],arr[20];
void solve1(){
    ll res = 0;
    for (char c : num){
        ll cur = dig[c - '0'],cnt = 0;
        for (int i = 0 ; i < 7 ; i++){
            if (cur & (1 << i)){
                cnt++;
            }
        }
        res += cnt;
    }
    cout << res;
}
void solve2(){
    for (int i = 0 ; i < num.size() ; i++){
        char c = num[i];
        for (int j = 0 ; j < 10 ; j++){
            if ((dig[j] & dig[c - '0']) == dig[c - '0']){
                eq[i]++;
                if (j > c - '0') arr[i]++;
            }
        }
    }
    ll res = 0;
    for (int i = num.size() - 1 ; i >= 0 ; i--){
        ll tot = arr[i];
        for (int j = i+1 ; j < num.size(); j++){
            tot *= eq[j];
        }
        res += tot;
    }
    cout << res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("LED.inp","r",stdin);
    freopen("LED.out","w",stdout);
    cin >> opt;
    cin >> num;
    if (opt == 1) solve1();
    else solve2();
}