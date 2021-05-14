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
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
string keyword,s;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("secrtin.txt","r",stdin);
    freopen("secrtout.txt","w",stdout);
    cin >> keyword >> s;
    for (int i = 0 ; i < s.size() ; i++){
        ll cur = s[i] - 'A'; ll pos = i % keyword.size();
        ll advance = keyword[pos] - 'A' + 1; //cout << advance << " ";
        s[i] = 'A' + (cur + advance) % 26;
        //cout << endl;
    }
    cout << s;
    return 0;
}