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
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e3 +2  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int st ;
vector<pair<int ,int >> graph [N];
bool vis[N];
int deg[N];
vector<tuple<int , int ,int >> ans ;
void clear(){
    for(int i =0 ; i <N ; i++) vis[i] =0;
}
void dfs(int sn, int & mn ) {
    vis[sn] = 1 ;
    for(auto ch : graph[sn]){
        if(vis[ch.f]) return ;
        if(!vis[ch.f]){
            if(ch.s < mn ) mn = ch.s;
            if(deg[ch.f] ==1) {
                ans.pb({st, ch.f, mn});
            }
            dfs(ch.f, mn);
        }


    }


}
void EZ(){
    int n , m;
    cin >> n >> m ;
    for(int i =0 ; i < m ; i++) {
        int u , v ,w ; cin >> u >> v >> w ;
        graph[u].pb({v ,w});
        deg[u]++;
        deg[v]++;
    }
    
    for(int i =1 ; i<=n ;i++) {
            if(deg[i]==1) {
                clear();
                int mn = 1e9 ;
                st =i ;
                dfs(i, mn);
            }
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << get<0>(i) << " " <<get<1>(i) << " " <<  get<2>(i) << endl;


}


int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc =1 ;
  //  cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


