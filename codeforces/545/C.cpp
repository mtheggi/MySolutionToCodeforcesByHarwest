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
const int MOD = 2e9+1;
const double EPS = 1e-9;
const int N = 1e6  + 20 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

void EZ(){
    int n; cin >> n;
    vector<pair<ll ,ll >> tree ;
    for(int i = 0 ; i < n ; i++) {
        int a, b ; cin >> a >> b ;
        tree.emplace_back(make_pair(a, b ));
    }
    tree.emplace_back(make_pair(MOD,MOD));
    ll ans =( 1 );
    ll  limit=(tree[0].f);
    for(int i = 1 ; i < n ; i++) {
        if((tree[i].f - tree[i].s) > limit) {
                ans++;
                limit = tree[i].f ;
        }else if((tree[i].f  + tree[i].s) < tree[i+1].f ){
            ans++;
            limit= tree[i].f + tree[i].s;
        }else {limit = tree[i].f ;}
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
 //   cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


