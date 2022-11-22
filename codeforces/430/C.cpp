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
//const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e5 +4  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

vector<int > ans;
vector<int> adjlist[N];
int lvl[N];
bool vis[N], init[N], goal[N];
bool toggleEven =0 , toggleOdd =0 ;
void dfs (int node , int level , bool toggleEven , bool toggleOdd ){
        lvl[node] = level;
        vis[node] =1 ;
        if((level % 2 == 0)  && toggleEven) init[node]^= 1;
        if(level&1  && toggleOdd) init[node]^=1 ;
        if(init[node]  != goal[node]){
            ans.pb(node);
            if(level%2 ==0 ) toggleEven ^= 1;
            else toggleOdd ^= 1;
        }
       for(auto child : adjlist[node]) if(!vis[child]) dfs(child, level + 1 , toggleEven , toggleOdd);
}
void EZ(){
    int n , u , v; cin >> n;
    for(int i =0 ; i< n-1 ;i++) {
        cin >> u >> v;
        adjlist[v].pb(u);
        adjlist[u].pb(v);
    }
    for(int i =1 ; i<=n ;i++) cin >> init[i];
    for(int i = 1; i<= n ; i++) cin >> goal[i];
    dfs(1,  1 , 0, 0);
    for(int i =  1 ; i <=n; i++) cerr << init[i];
     cerr << endl ;
    for(int i =  1 ; i <=n; i++) cerr << goal[i];

    cout << ans.size() << el;
    for(auto  i : ans ) cout << i << endl;
}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error","w",stderr);
#endif

    int tc =1 ;
    // cin >> tc;
    for(int i =1 ; i <=tc ; i++) EZ();
    ShowTime
    return 0 ;
}


