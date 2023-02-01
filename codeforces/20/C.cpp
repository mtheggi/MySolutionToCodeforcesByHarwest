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
const int N = 2e5 +2  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
// node1  -> node2 -> weight ;
vector<pair<int , int >> g[N];
ll dist[N] ,n ;
int previous[N];

void dijkstra( int src ) {
    for(int i = 1 ; i<=n ; i++){ dist[i] = 1e18; previous[i] = 0;  }
    dist[src] =0;
    previous[src] = 1 ;
    // weight - node
    priority_queue<pair<ll ,int >> pq ;
    pq.push({0 , src});
    while(!pq.empty()){
        ll node  = pq.top().s , currentCost = -1 * pq.top().f ;
        pq.pop();
        for(auto  child : g[node]){
            if(dist[child.f] > currentCost + child.s ){
                previous[child.f] = node;
                dist[child.f] =  currentCost + child.s;
                pq.push({-1 * (currentCost + child.s) , child.f});
            }
        }
    }

}
void EZ() {
    int m; cin >> n >> m;
    for(int i =0 ;i < m;i++) {
        int a , b , c; cin >> a >>b >> c;
        g[b].pb({a,c});
        g[a].pb({b,c});
    }
    dijkstra(1);
    vector <ll> res;
    if(dist[n] == 1e18) {cout << -1 << endl; re;}

    while(n != 1 ){
        res.pb(n);
        n= previous[n];
    }
    res.pb(1);
    reverse(all(res));
    for(auto i : res ) cout << i << ' ' ;
}

int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ;  //cin >> tc;
    while(tc--){
        EZ();
    }
    ShowTime
    return 0 ;
}