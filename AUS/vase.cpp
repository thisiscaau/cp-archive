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
ll a,b,c,n;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("vasesin.txt","r",stdin);
    freopen("vasesout.txt","w",stdout);
    cin >> n;
    if (n < 6){
        cout << "0 0 0";
        return 0;
    }
    else {
        if (n % 3 == 0){
            cout << n/3 - 1 << " " << n/3 << " " << n/3 + 1;
        }
        else if (n % 3 == 1){
            ll k = (n-1)/3;
            cout << k-1 << " " << k << " " << k+2;
        }
        else {
            ll k = (n-2)/3;
            cout << k-1 << " " << k+1 << " " << k+2;
        }
    }
}