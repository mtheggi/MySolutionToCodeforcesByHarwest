// Just Keep it up, long way to go.
#include<bits/stdc++.h>

using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld double
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
#define popcntll(a) __builtin_popcountll(a)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
// Debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " :" << x << endl;
#define debugv(v) cerr << #v << endl;  for(auto & i : v ) cerr << i << " " ; cerr << endl;
#define debugp(p) cerr << #p << endl; for(auto  & i : p ) cerr << i.f << " " << i.s << endl;
#define ShowTime cerr << "Code Takes  : " << (float) clock() / CLOCKS_PER_SEC << setprecision(7) <<  fixed << " Secs to run." << endl;
#else
#define debug(x)
#define debugv(v)
#define ShowTime
#endif
// constants
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const int N = 1e6;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

ll fastpow(ll b, ll p) {
    if (!p) return 1;
    ll ret = fastpow(b, p >> 1);
    ret *= ret;
    if (p & 1) ret *= b;
    return ret;
}

void EZ() {
    int sum , limit ; cin >> sum >> limit ;
    vector<pair<int ,int >> v;
    for(int i =1; i <=limit ; i++) {
        v.pb({(i&-i) ,i });
    }
    sort(allr(v));
    vector<int> ans;
    for(int i =0 ;i < len(v) ; i++) {
        if((sum-v[i].f) >=0 ){
            sum-=v[i].f;
            ans.pb(v[i].s) ;
        }
    }
    if(sum) cout << -1 << el;
    else{ cout << len(ans) << el;  for(auto i : ans ) cout << i << " "  ;  cout << el; }

}

int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        EZ();
    }
    ShowTime
    return 0;
}


