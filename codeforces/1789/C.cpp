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
#define len(z) (ll)z.size()
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
const ll MOD = 1e9+7;
const double EPS = 1e-9;
const ll N = 4e5 +2  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

ll n ,m , a , b  ;

ll llerval[N];
ll freq[N];
bool vis[N];
void EZ(){
    cin >> n >> m ;
    for(ll i =0 ;i <= (n+m +2 ) ; i++) {llerval[i] =-1 ; freq[i] =0  ; vis[i] =0 ; }
    vector<ll> v(n+1) ;
    for(ll i =1 ;i <= n ; i++) {cin >> v[i];   vis[v[i]]  = 1 ; llerval[v[i]] =0 ;  }
    for(ll i =1;i <= m ;  i++) {
        cin >> a >> b;
        if (v[a] != b)
        {       vis[b] = 1;
                freq[v[a]] += (i - llerval[v[a]]);
                llerval[b] = i;
                llerval[v[a]] = -1;
                v[a]= b;
        }
    }
    for(ll i =1 ;i <= (n+m) ; i++ ){
          if( llerval[i] != -1  && vis[i]) {
            freq[i] +=(m+1 - llerval[i]);
          }
    }
    ll sum =(m*(m+1)) /2  , ans =0 ;
    for(ll i =1 ;i <= (n+m) ; i++){
            ans +=(sum - ((m - freq[i] )* (m-freq[i]+1)) /2);
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

    ll tc =1 ;
    cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


