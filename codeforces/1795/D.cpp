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
const int MOD = 998244353;
const double EPS = 1e-9;
const int N = 1e6 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

class ModOp{
    long long  MOD ;
public :
    ModOp():MOD(1e9 + 7 ){}
    ModOp(ll M ):MOD(M){}
    void setMOD(ll M ) {MOD = M ; }
    ll add( ll a, ll b ) {return(a+ b + MOD) % MOD ; }
    ll mul(ll a,ll b ) {return( a * b % MOD);}
    ll FastPower(ll a , ll b ) {
        ll z = 1;
        while(b)
        {
            if(b % 2 == 1) z = mul(z, a);
            a = mul(a, a);
            b /= 2;
        }
        return z;
    }
    ll inverseMod(ll a ) {return FastPower( a , MOD-2 ); }
    ll divide(ll a, ll b ) { return mul(a , inverseMod(b)) ;}
};
ModOp md(MOD);
ll combination(ll c, ll r) {
    if (r > c) return 0;
    ll ans = 1;
    for (ll i = 0; i < r; i++) ans = md.divide(md.mul(ans , c-i) , i+1 );
    re ans;
}

void EZ(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0 ;i < n ;i++)  cin>>v[i];
    ll ans = combination(n/3 , n/6 );

    for(int i =0 ;i < n  ; i+=3  ) {
        int x = v[i] , y = v[i+1] , z = v[i+2];
        cerr << x << " " << y << " " << z << el;
        int mx = max(x , max(z,y));
        if(x == y && y == z ){
            ans = (ans%MOD *3 )%MOD;
        }else if( x == y && mx == z || z == x && mx == y ||y == z && mx == x  ){
            ans = (ans%MOD *2 )%MOD;
        }
        cerr << ans%MOD << el;

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


