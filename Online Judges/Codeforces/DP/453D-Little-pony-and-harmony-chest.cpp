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
ll a[105],b[105];
ll mask[65];
ll dp[105][1 << 18];
ll pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
string print(ll msk){
    string res = "";
    for (int i = 0 ; i < 17 ; i++){
        if (msk & (1 << i)){
            res += "1";
        }
        else {
            res += "0";
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    // dp[i][mask] minimum cost to be at index i and have mask 
    for (int i = 1 ; i <= 60 ; i++){
        for (int j = 0 ; j < 17 ; j++){
            if (i % pr[j] == 0){
                mask[i] ^= (1 << j); // flip
            }
        }
    }
    // dp goes here
    memset(dp,inf,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1 ; i <= n ; i++){
        for (int val = 1 ; val < 60 ; val++){
            ll msk = (~mask[val]) & ((1 << 17) - 1);
            // mask that dont conflict
            // get all submask of above
            for (int s = msk ; ; s = (s-1) & msk){
                dp[i][s | mask[val]] = min(dp[i-1][s]+abs(a[i]-val),dp[i][s | mask[val]]);
                if (s == 0) break;
            }
        }
    } 
    ll msk,cost = inf;
    for (int i = 0 ; i < (1 << 17) ; i++){
        if (dp[n][i] < cost){
            cost = dp[n][i];
            msk = i;
        }
    }
    for (int i = n ; i >= 1 ; i--){
        //cout << print(msk) << endl;
        for (int val = 1 ; val < 60 ; val++){
            ll tmp = msk; bool skip = false;
            for (int bit = 0 ; bit < 17 ; bit++){
                if (mask[val] & (1 << bit)){
                    if (tmp & (1 << bit)){
                        tmp ^= (1 << bit);
                    }
                    else {
                        skip = true;
                        break;
                    }
                }
            }
            if (skip) continue;
            if (dp[i-1][tmp] + abs(a[i] - val) == cost){
                b[i] = val; cost -= abs(a[i] - b[i]);
                msk = tmp;
                //cout << print(mask[val]) << " " << val << endl;
                //cout << print(msk) << endl;
                //cout << "-------" << endl;
                break;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++){
        cout << b[i] << " ";
    }
}