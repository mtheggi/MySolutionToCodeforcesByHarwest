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
const int N = 1e6 ;
const int offset = 150000;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int n;
int  parent[N] ;
int sz[N];
int find(int a) {
    if(parent[a] == a ) return a ;
    else return parent[a] = find(parent[a]);
}
void connect(int a, int b) {
    int roota = find(a), rootb= find(b) ;
    if(roota == rootb) return ;
    if(sz[roota] >= sz[rootb]) sz[roota]+=sz[rootb] , parent[rootb] = roota;
    else sz[rootb]+=sz[rootb] , parent[roota] = rootb;
}
vector<vector<int>> g(N);
vector<bool> vis(N, 0 );
void dfs( int start ) {
    if(vis[start]) return;
    cout << start << " ";
    vis[start] =1;
    for(auto i : g[start]){
        if(!vis[i])
            dfs(i);

    }
}
void EZ() {
    cin >> n ;
    for(int i = 1 ; i<=n ; i++) {
        parent[i] =i ;
        sz[i] =1 ;
    }
    for(int i =1 ; i< n ;i++) {
        int a , b ; cin >> a >> b;
        g[find(a)].pb(find(b));
        g[find(b)].pb(find(a));
        connect(a,b);
    }
    dfs(find(1));




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
    while(tc-- ){
        EZ();
    }

    ShowTime
    return 0 ;
}


