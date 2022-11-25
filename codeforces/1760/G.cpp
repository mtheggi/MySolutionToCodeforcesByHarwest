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
const int N = 1e5+ 4 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int dx[] = {0 , 0, 1 ,-1 };
int dy[] = {1 , -1, 0 ,0 };
int n ,a ,b ,w  ;
vector<pair<int ,int >> graph[N];
bool vis[N] ;
set<int> atob,btoa;
void dfs(int node,int target,int x,bool ok) {
    vis[node] =1 ;
    for(auto i : graph[node]){
        if((i.f == target  && ok ) || vis[i.f] ) continue;
        if( !vis[i.f] ){
            if(ok) atob.insert(i.s^x) ;
            else  btoa.insert(i.s^x) ;
            dfs(i.f , target ,  x^i.s , ok );
        }
    }
}
void clear() {
    for(int i =0 ; i< N ; i++){
        vis[i] = 0;
        graph[i].clear();
    }
    atob.clear();
    btoa.clear();
}
void EZ(){
    clear();
    cin >> n >> a >>  b  ;
    for(int i = 1  ; i < n ;i++) {
        int u ,v;
        cin >> u >>v >> w  ;
        graph[u].pb({ v, w }) ;
        graph[v].pb({ u, w }) ;
    }
    dfs(a , b , 0 , 1 );
    for(int i =0 ; i< N ; i++) vis[i] = 0;
    dfs(b , a , 0 , 0 );
    if(btoa.count(0))  YES;
    else {
        for(auto i  : atob) {
            if(btoa.count(i)){
                YES;
                return;
            }
        }
        NO;
    }


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
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


