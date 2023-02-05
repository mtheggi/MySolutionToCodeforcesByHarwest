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
const int N = 2e5 +5  ;
const ll inf = 1e18 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
int n, m;
ll dist[N];
vector<pair<int , ll >> g[N];
void dijkstra(){
    priority_queue<pair<ll ,int >> pq ;
    for(int i =1 ; i<=n ; i++) pq.emplace(-dist[i], i );
    ll cost ; int u ;
    while(pq.size()){
        tie(cost , u ) = pq.top();
        cost *=-1;
        pq.pop();
        if(cost > dist[u] ) continue;
        for(auto ch  : g[u]){
            ll edgecost = 2 * ch.s , newnode =ch.f ;
            if(cost +  edgecost  < dist[newnode]){
                dist[newnode] = cost + edgecost ;
                pq.emplace(-dist[newnode] , newnode);
            }

        }
    }
}
void EZ() {
    cin >> n >> m;
    ll u ,v ;ll w;
    for(int i= 0 ;i < m ;i++) {cin >>u >> v >> w  ; g[u].emplace_back(v ,w ); g[v].emplace_back(u ,w ); }
    for(int i =1 ; i<= n ; i++) {cin >> u ; dist[i] = u ;}
    dijkstra();
    for(int i = 1; i<=n ; i++) {cout << dist[i] << " "; }

}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ; // cin >> tc;
    while(tc--){
        EZ();
    }
    ShowTime
    return 0 ;
}