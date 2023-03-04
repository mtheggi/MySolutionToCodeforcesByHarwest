// Just Keep it up, long way to go.
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
const int MOD = 998244353;
const double EPS = 1e-9;
const int N = 1e6 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }


void EZ(){
    int n; cin >>n ;
    string t ;
    cin >> t;
    for(int i =0 ; i < t.size() ; i++) { t[i] = toupper(t[i]);  }
    int m  =t.find('M') , e = t.find('E') , o= t.find('O') , w =t.find('W');
    cerr << t << " " << m  <<  " "   << e << " " << o << " " <<  w << el;
    if(m == string::npos || e == string::npos  || o == string::npos|| w == string::npos ) {NO; re;  }
    for(int i= 0 ;i < e ; i++) {if(t[i] != 'M'){NO; re; }}
    for(int i = e ; i< o ;  i++) if(t[i] != 'E') { NO ;re; }
    for(int i = o ; i < w ; i++) if(t[i] != 'O') {NO ;re; }
    for(int i =w ; i < t.size() ; i++) {if(t[i] != 'W') {NO ; re; }}

    YES ;



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
    return 0 ;
}


