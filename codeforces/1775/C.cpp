// Just Keep it up, long way to go.
#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll unsigned  long long
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
const int N = 1e6 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

// HEYYYY !! I am back in the game
ll calcand(ll n , ll m ){
    ll ans =0 ;
    for( int bits = 63 ; bits >=0 ; bits-- ){
        if((n&(1ll<<bits)) == (m & (1ll<<bits))){
            ans|= (m& (1ll<<bits ));
        }else break;
    }
    return ans;
}



void EZ() {
    ll n, x;  cin >> n >> x;
    if(n == x) {cout << n << el; re;}
    if( x > n ) {cout << -1 << el;re ;}
    bool r = 0;
    ll mid,  start =n , end = 5e18 , m;
    while(start <= end ) {
        mid = (start + end )/ 2 ;
        ll z = calcand(n, mid);
        //cerr << z << endl ;
        if(z < x ) {
            end = mid -1 ;
        }else if(z> x ) {
            start = mid + 1;
        }else if (z == x ){
         
            m = mid ;
            r = 1;
            end = mid-1;
        }
    }
    if(r)
    cout << m << endl ;
    else
        cout << -1 << endl;

}


int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc;  cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


