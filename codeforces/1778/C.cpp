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
const int N = 1e3 +10  ;
const ll inf = 1e18 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
int n , k;
string t1 ,t2 ;
void EZ() {
    cin >> n >> k;
    cin >> t1 >> t2 ;
    set<char> chng;
    for(int i =0 ;i < n ;i++) {if(t1[i] != t2[i]) chng.insert(t1[i]) ; }
    vector<char> tochng(all(chng)) ;
    int limit = (1ll <<(tochng.size())  );
    ll mx = -1 , sum =0 , c =0 ;
    for(int msk = 0 ; msk <= limit ;msk++) {
            if(__builtin_popcount(msk) <=k ){
                vector<bool> visited(28, 0 );
                for(int i =0 ; i< tochng.size() ; i++ ){
                    if(msk&(1<<i)){
                        visited[tochng[i] - 'a']=1 ;
                    }
                }
                sum =0 ; c=0;
                for(int i =0 ;i < n ;i++) {
                    if(visited[t1[i]- 'a'] || t1[i] == t2[i]) c++;
                    else{sum+=(c + (c* (c-1))/2 ); c=0 ; }
                }
                sum+=(c + (c* (c-1))/2 ); c=0 ;
                mx = max(mx , sum );
            }
    }
    cout << mx  << "\n";
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
    return 0  ;
}