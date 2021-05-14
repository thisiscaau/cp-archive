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
#define PI 3.14159265
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
vector<ll> vi;
/* workspace */
bool check(ll a,ll b,ll c){
    if (a + b <= c) return false;
    if (b + c <= a) return false;
    if (c + a <= b) return false;
    return true;
}
bool check_edge(){
    if (!check(vi[0],vi[1],vi[2])) return false;
    if (!check(vi[0],vi[3],vi[4])) return false;
    if (!check(vi[1],vi[4],vi[5])) return false;
    if (!check(vi[3],vi[5],vi[2])) return false;
    return true;
}
bool check_permu(){
    if (!check_edge()) return false;
    
    double BAD,ADB,ABD,DBC,DCB,BDC,DAC,DCA,ADC,BAC,ACB,ABC;
    ll AB = vi[0], BC = vi[1], AC = vi[2] , AD = vi[3], BD = vi[4], CD = vi[5];
    // ABD
    BAD = acos((double)(((AB*AB+AD*AD-BD*BD)*1.0)/(2*AB*AD*1.0))) * 180.0 / PI;
    if (isnan(BAD)) return false;
    ABD = acos((double)(((AB*AB-AD*AD+BD*BD)*1.0)/(2*AB*BD*1.0))) * 180.0 / PI;
    if (isnan(ABD)) return false;
    ADB = acos((double)(((-AB*AB+AD*AD+BD*BD)*1.0)/(2*BD*AD*1.0))) * 180.0 / PI;
    if (isnan(ADB)) return false;
    // BDC
    BDC = acos((double)(((CD*CD-BC*BC+BD*BD)*1.0)/(2*CD*BD*1.0))) * 180.0 / PI;
    if (isnan(BDC)) return false;
    DBC = acos((double)(((-CD*CD+BC*BC+BD*BD)*1.0)/(2*BC*BD*1.0))) * 180.0 / PI;
    if (isnan(DBC)) return false;
    DCB = acos((double)(((CD*CD+BC*BC-BD*BD)*1.0)/(2*CD*BC*1.0))) * 180.0 / PI;
    if (isnan(DCB)) return false;
    // ADC
    DCA = acos((double)(((CD*CD-AD*AD+AC*AC)*1.0)/(2*CD*AC*1.0))) * 180.0 / PI;
    if (isnan(DCA)) return false;
    ADC = acos((double)(((CD*CD+AD*AD-AC*AC)*1.0)/(2*CD*AD*1.0))) * 180.0 / PI;
    if (isnan(ADC)) return false;
    DAC = acos((double)(((-CD*CD+AD*AD+AC*AC)*1.0)/(2*AC*AD*1.0))) * 180.0 / PI;
    if (isnan(DAC)) return false;
    // ABC
    ABC = acos((double)(((AB*AB+BC*BC-AC*AC)*1.0)/(2*AB*BC*1.0))) * 180.0 / PI;
    if (isnan(ABC)) return false;
    BAC = acos((double)(((AB*AB-BC*BC+AC*AC)*1.0)/(2*AB*AC*1.0))) * 180.0 / PI;
    if (isnan(BAC)) return false;
    ACB = acos((double)(((-AB*AB+BC*BC+AC*AC)*1.0)/(2*AC*BC*1.0))) * 180.0 / PI;
    if (isnan(ACB)) return false;
    // CHECK ANGLE
    //cout << BAD << " " << BAC << " " << DAC << endl;
    if (BAD + BAC + DAC >= 360) return false;
    //cout << ABD << " " << DBC << " " << ABC << endl;
    if (ABD + DBC + ABC >= 360) return false;
    //cout << ACB << " " << DCA << " " << DCB << endl;
    if (ACB + DCA + DCB >= 360) return false;
    //cout << BDC << " " << ADB << " " << ADC << endl;
    if (BDC + ADB + ADC >= 360) return false;
    // CHECK A
    if (BAD + BAC <= DAC) return false;
    if (BAD + DAC <= BAC) return false;
    if (BAC + DAC <= BAD) return false;
    // CHECK B
    if (ABD + DBC <= ABC) return false;
    if (ABD + ABC <= DBC) return false;
    if (DBC + ABC <= ABD) return false;
    // CHECK C
    if (ACB + DCA <= DCB) return false;
    if (ACB + DCB <= DCA) return false;
    if (DCB + DCA <= ACB) return false;
    // CHECK D
    if (BDC + ADB <= ADC) return false;
    if (BDC + ADC <= ADB) return false;
    if (ADB + ADC <= BDC) return false;
    // everything is ok
    return true;
}
void solve(){
    vi.clear();
    for (int i = 1 ; i <= 6 ; i++){
        ll a; cin >> a;
        vi.pb(a);
    }
    sort(vi.begin(),vi.end());
    bool ok = false;
    if (check_permu()){
        cout << "Yes" << endl;
        return;
    }
    while (next_permutation(vi.begin(),vi.end())){
        if (check_permu()){
            ok = true;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--){
        solve();
    }
}