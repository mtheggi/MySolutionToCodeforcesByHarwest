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
const ll MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e5 +10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int n, k ,d  ;
vector<int> v;
ll freq[N];
ll dp[102][2];
int sz;
ll findpath(int rem , bool f  ) {
    if (rem < 0) return 0;
    if (rem == 0) re f;
    if (dp[rem][f] != -1) return dp[rem][f];
    ll z = 0;
    for (int i = 1; i <= min(rem, k ); i++) {
            z += findpath(rem - i,(f|| i>=d ));
    }
    return dp[rem][f] = z%MOD;
}

    void EZ() {
        for (int i = 0; i < 102; i++) dp[i][0] = dp[i][1] =  -1;
        cin >> n >> k >> d;
        v.resize(k + 1);
        v[0] = 0;
        ll x = findpath(n, 0);
        cout << x << el;

    }


    int main() {

        RunIt;
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
        // freopen("Error", "w", stderr);
#endif

        int tc = 1;
//     cin >> tc;
        while (tc--) {
            EZ();
        }

        ShowTime
        return 0;
}
