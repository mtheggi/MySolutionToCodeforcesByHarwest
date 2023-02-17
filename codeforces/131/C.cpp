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
const int N = 31622 + 20  ,  M = 2e5 + 10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

ll combination(int c , int r ) {
    if(r > c ) return 0;
    lld ans = 1;
    for(int i = 0 ;i < r; i++) ans=(ans*(lld)(c-i))/(i+1);
    re ans;
}

void EZ() {
    int n , m, t; cin >> n >> m >>t ;
    ll onlygirls =  combination(m,t), onlyboys = combination(n,t)   ;
    ll oneboy = combination(n,1) * combination(m,t-1);
    ll twoboys  = combination(n, 2) * combination(m , t-2) , threeboys= combination(n,3) * combination(m, t-3 );
    cout <<  combination(n+m , t) - onlygirls- onlyboys - oneboy - twoboys - threeboys << el ;
}

int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ; //cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}

