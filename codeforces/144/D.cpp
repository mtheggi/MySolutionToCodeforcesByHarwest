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
const ll MOD = LLONG_MAX;
const double EPS = 1e-9;
const int N = 5e5 +10  ;
const ll inf = 1e18 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
vector<pair<int ,int >> g[N];
ll dist[N];
int n, m  ,l  , t ;
int ans = 0 ;
bool vis[N] ;
void dikstra(int src ){
    for(int i =1 ;i <= n ;i++) dist[i] =MOD;
    dist[src] =0 ;
    priority_queue<pair<ll , int >> pq ;
    pq.emplace( 0 , src) ;
    ll c, u;
    while(pq.size() ) {
        tie(c , u ) = pq.top() ;
        c*=-1 ;
        pq.pop();
        if(c  > dist[u]) continue;
        for(auto ch : g[u]) {
            ll edgecost = ch.s  , newnode = ch.f ;
            if(edgecost + c < dist[newnode]) {
                dist[newnode] = edgecost + c ;
                pq.emplace(- dist[newnode] , newnode);
            }
        }
    }
}
void EZ(int tc) {
    cin >> n >> m >> t ;
    vector<pair< pair<int ,int > , int  >> edges;
    for(int i  =0 ;i <  m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges.pb({{u, v}, w});
    }
    cin >> l ;
    dikstra(t);
    for(int i  =1 ;i <=n ; i++){  if(dist[i] == l ) ans++; }

    for(int i =0 ;i <m; i++ ){
        int path1 = dist[edges[i].f.s] , path2 = dist[edges[i].f.f] , cost = edges[i].s;
        if(path1<l && l-path1 < cost ) if(( path2+(cost - l+ path1) >= l )) ans++ ;
        if(path2<l && l-path2 < cost ) if(( path1+(cost - l+ path2) > l )) ans++ ;
    }
    cout << ans << '\n';
}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ;
//    cin >> tc;
    for(int i =1 ; i<=tc ; i++)
        EZ(i);

    ShowTime
    return 0  ;
}