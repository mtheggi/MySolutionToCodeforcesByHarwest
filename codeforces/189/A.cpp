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
int n , a, b , c;
vector<int>  v ;
int dp[4002][4002];
int maxribbons(int n , int sz ) {
    if(n == 0 ) return sz ;
    if(n< 0 ) return 0;

    if(dp[n][sz] != -1 ) return dp[n][sz];
    int z = maxribbons( n-a , sz +1 );
    int z2 = maxribbons(n-b, sz+1 );
    int z3 = maxribbons(n-c , sz+1 ) ;


    return dp[n][sz] = max(z , max(z2 , z3 )) ;
}

void EZ(){
    cin >> n >> a >> b >> c ;
    memset(dp  , -1 , sizeof dp );
    cout << maxribbons( n , 0 ) << el;
}
int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc =1 ;
 //   cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


