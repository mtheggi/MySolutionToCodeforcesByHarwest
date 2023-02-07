#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long double
#define el endl
#define re return
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define f first
#define s second
#define len(z) (int)z.size()
#define pb push_back
#define eb emplace_back
#define popcnt(a) __builtin_popcount(a)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
// Debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " :" << x << endl;
#define debugv(v) cerr << #v << endl;  for(auto & i : v ) cerr << i << " " ; cerr << endl;
#define ShowTime cerr << "Code Takes  : " << (float) clock() / CLOCKS_PER_SEC << setprecision(7) <<  fixed << " Secs to run." << endl;
#else
#define debug(x)
    #define debugv(v)
    #define ShowTime
#endif
// constants
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e3 +10  ;
const ll inf = 1e18 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }

void EZ() {
    int n , m  , d ;
    cin >> n >> m >> d;
    vector<int> p(n +1 ) , a(m) ;
    map<int ,int > pos ;
    for(int i =1 ; i <=  n ;i++) {cin >> p[i] ; pos[p[i]] = i;  }
    for(auto & i :a ) cin >> i ;
    int ans =INT_MAX;
    debugv(a);
    for(int i =0 ; i < m-1  ; i++ ){
        if(pos[a[i]] > pos[a[i+1]] || pos[a[i]]+ d < pos[a[i+1]]) {cout << 0 << el; re; }
        //cerr  << d +1 - pos[a[i+1]] + pos[a[i]] << " " << pos[a[i+1]] - pos[a[i]] << el;
        int option1 = d +1 - pos[a[i+1]] + pos[a[i]] ;
        int option2 =pos[a[i+1]] - pos[a[i]]  ;
       // cerr << option1 << " " << option2 << el;
        if( (pos[a[i]] -1  + n- pos[a[i+1]] ) <= (d-  abs(pos[a[i]] - pos[a[i+1]]))  ) option1 =INT_MAX;
        ans= min(ans, min(option1, option2));
    }
    cout << ans << el;

}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ;
    cin >> tc;
    while(tc--){
        EZ();
    }
    ShowTime
    return 0  ;
}