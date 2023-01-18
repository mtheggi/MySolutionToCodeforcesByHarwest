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
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
int n, comp , k;
int parent [N] ;
int sz[N];
void init() {
    for(int i =1 ; i<= n ;i++){
        parent[i]= i;
        sz[i]= 1;
    }
}
int find(int a ) {
    if(parent[a] == a) return a ;
    else {
        return parent[a] = find(parent[a]);
    }
}
void connect( int u , int v)
{
    u = find(u);
    v = find(v);
    if ( u == v)return ;
    if(sz[v] < sz[u])
        parent[v] = u ,sz[u] += sz[v];
    else
        parent[u] = v,sz[v] += sz[u];
}
void EZ() {
    cin >> n>> k;
    comp= n ;
    init();
    for(int i =0 ;i < n-1 ; i++){
        int a, b,c ; cin >> a>> b >> c;
        if(!c)
            connect(a ,b );
    }
    vector<bool> check(n+1, 0 );
    ll ans =0 ;

    for(int i =1 ; i <= n; i++){
        int node = find(i);
        if(!check[node]){
            check[node] =1 ;
            if(sz[node] != 1 ){
              ans+= fastpow(sz[node], k);
              ans= ans%MOD;
            }else {ans++;}
        }
    }
    cout << (fastpow(n,k) -  ans + MOD )%MOD  << endl;
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


