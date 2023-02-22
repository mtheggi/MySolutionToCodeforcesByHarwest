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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int N = 1e6  + 20 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
int a, b ,n ;
ll inv[N];
ll binarypower( ll b , ll p){
    if(p == 0 ) re 1 ;
    if(p == 1 ) re b ;
    ll z = binarypower( b, p>>1 );
    z = (z%MOD * z%MOD )%MOD ;
    if(p & 1) {  z = ((z % MOD)*(b %MOD ))%MOD ; }
    re z ;
}
bool checkgood( ll z ){
    while(z){
        if(z%10 != a && z%10 != b ) return 0 ;
        z/=10;
    }
    return 1;
}
void calcinverse(){
    for(int i =1 ;i <N  ;i++) {
        inv[i] = binarypower(i , MOD-2 );
    }
}

ll mulmod(ll a, ll b){
    return ((a%MOD * b%MOD)%MOD);
}
ll addmod(ll a , ll b) {
    return (a + b + MOD )%MOD;
}
ll nCr(int a,  int b ){
    ll ans = 1 ;
    for(int i =0 ; i <b ; i++) {
        ans = mulmod(mulmod(ans , addmod(a , -i )), inv[i+1]);
    }
    return ans;
}
void EZ(){
    calcinverse();
    cin >> a >> b >> n;
    ll ans =0 ;
    for(int i =0 ;i <= n; i++) {
        ll z = a *i + b*(n-i);
         //cerr << z << el;
        if(checkgood( z )  ){
            //cerr << "lol" << el;
             ans = addmod(ans , nCr(n,i));
        }
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
    //cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


