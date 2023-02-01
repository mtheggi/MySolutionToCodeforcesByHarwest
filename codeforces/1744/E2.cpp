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
const int N = 3 ;
const int offset = 150000;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

void EZ(){
    ll a, b , c , d;
    cin >> a >> b >> c >> d ;
    vector<ll> f_a , f_b  ;
    vector<ll> f_ab ;
    for(int i =1 ; i *i <= a ; i++) if (a%i == 0 ) {f_a.pb(i); f_a.pb(a/i); }
    for(int i =1 ; i *i <= b ; i++) if (b%i == 0 ) {f_b.pb(i); f_b.pb(b/i); }
    // fab = fa + fb + fa(i) * fb(j);
    for(ll i : f_a)
        for(ll j : f_b) {
            f_ab.pb(1ll * i * j ) ;
        }
    ll  x = - 1, y = -1 ;
    for(auto f1 : f_ab) {
        ll f2 = (1ll * a * b )/ f1;
         if(a < (c - c%f1) && b < (d -d%f2)){
             x = c - c%f1 ;
             y = d - d%f2 ;
             break;
         }
         swap(f1 ,f2 );
        if(a < (c - c%f1) && b < (d -d%f2)){
            x = c - c%f1 ;
            y = d - d%f2 ;
            break;
        }
    }
    cout << x << " " << y << endl;
}

int main()
{
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("Output.txt", "wt", stdout);
#endif
    int tc =1 ;
    cin >> tc;
    while(tc--){
        EZ();
    }
    return 0;
}