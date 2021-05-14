#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ull unsigned long long
#define endl '\n'
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back 
#define ceil(x,y) (x+y-1)/y
#define deb(x) { cerr << #x << '=' << x << '\n'; }
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;
    vector<int> pos[26];
    for (int i = 0; i < (int) s.size(); ++i){
        pos[s[i] - 'a'].pb(i);
    }
    for (int i = 0; i < (int) t.size(); ++i){
        if (pos[t[i] - 'a'].empty()){
            cout << -1 << endl;
            return;
        }
    }
    t.pb('$');
    int cur = -1, res = 0;
    for (int i = 0; i < (int) t.size(); ++i){
        if (t[i] == '$'){
            res++;
            break;
        }
        int temp = t[i] - 'a';
        auto it = upper_bound(pos[temp].begin(), pos[temp].end(), cur);
        if (it == pos[temp].end()){
            res++;
            cur = -1;
            it = upper_bound(pos[temp].begin(), pos[temp].end(), cur);
            cur = *it;
        }
        else{
            cur = *it;
        }
    }
    cout << res << endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    int t;cin >> t;while(t--) 
    solve();
}

			  	   	    	 		 	 	 		 			 	