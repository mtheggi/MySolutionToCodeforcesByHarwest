#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long double
#define el endl
#define re return
#define YES cout << "Yes\n"
#define NO cout << "No\n"
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
const int N = 1e7 +2 ,  M = 2e5 + 10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int spf[N]; // smallest Prime Factor
///vector<int> primes[N];
void sieve()
{ // O(n * (log(log(n)))
    for (int i = 1; i < N; i++)
        spf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i + i; j < N; j += i)
        {
            spf[j] = min(spf[j], i);
        }
    }
}
vector<int> fact(int z )
{ //O(log(n))
    vector<int> p;
    while(z>1 ){
            int lpf = spf[z];
            while(z% lpf  == 0 ) z/= lpf;
            p.pb(lpf);
    }

    return p ;
}
int  x, y;
void EZ() {
    cin>> x >> y;

//        // 10009 + 1 - >
//        // 2 2 2 2 5 5 5 [2000] +1 -> 3 23 29
//
//    }
    if(x > y ) swap(x,y);
    if(gcd(x,y) != 1 ) {cout << 0 << el; re; }
    if(x == y ) {if(x == 1) cout << 1 << el; else cout << 0 << el; re; }
    int diff = y-x;
    if(diff == 1 ) {cout << -1 << el; re;  }
    vector<int> p = fact(diff);
    debugv(p);
    int ans = INT_MAX;
    for(int i = 0 ; i< p.size() ; i++) { ans = min(ans , (((x+p[i]-1)/p[i]) * p[i]) - x ) ; }
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
    sieve();
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}

