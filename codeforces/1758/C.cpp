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
const int N = 1000 ,  M = 1e5 + 10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
vector<int> ans ,fact;
int n ,x ;
vector<int> primfact(int n){
    vector<int> ans;
    for(int i= 2 ; i *i <= n ; i++){
        while(n% i == 0 ){
            ans.pb(i);
            n/=i;
        }
    }
    if(n > 1 ) ans.pb(n);
    re ans ;
}
void solve(int n ){
    vector<int>fact = primfact(n) ;
    int z =fact[0];
    if(n%z == 0 && (n/z)%z == 0 ) {ans[n/z] = n ; solve(n/z);}
    else{if(x== n ) return ; ans[x]=n ;re; }
}
void EZ() {
    cin >> n >> x;
    set<int>factors  ;
    int c = 1;
    int fi = x;
    if( n%x ) {cout << -1 << el;re ;}
    vector<int>ans(n+1, -1 );
    ans[1]=x  ;
    ans[n] =1 ;
    factors.insert(x);
    while(fi<=n ){
        //cerr << n << " " << *factors.rbegin() <<el;
        if(n%fi == 0 && fi%(*factors.rbegin()) == 0 ) {
            factors.insert(fi) ;
        }
        fi=x;
        c++ ;
        fi*=c ;
        //cerr << fi<<  el;
    }
    factors.insert(n);
    vector<int>facts(all(factors));
    for(int i =0 ; i< factors.size()-1  ;  i++ ){
        ans[facts[i]] = facts[i+1];
    }
    for(int i=1 ; i<=n ;i++) if(ans[i] == -1 ) cout << i << " " ; else cout << ans[i] << " ";
    cout << '\n';
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


