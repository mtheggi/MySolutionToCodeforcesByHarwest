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
const int N = 1e5 +10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

void EZ(){
   int n; cin >> n ;
   vector<int> v(n+1) ;
   set<int> st ;
   for(int i =1 ; i<=n ;i++){ cin >> v[i] ; st.insert(i) ;}
   int l =1  , r= n , mn , mx;
   bool found = false;
   while(!found && l<r){
       mn= *(st.begin()) ;
       mx = *(st.rbegin());
       int sz = st.size();
        if(v[l] == mn || v[l] == mx) { st.erase(v[l]); l++; }
        if(v[r] == mn || v[r] == mx ){st.erase(v[r]);r--;}
       if(sz == st.size()) {found =true ;break; }
   }
   if(found) cout << l << " " << r << el;
   else cout << -1 <<el;


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


