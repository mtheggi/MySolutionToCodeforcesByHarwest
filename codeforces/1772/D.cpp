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
const int N = 3 ;
const int offset = 150000;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1
    ); ret *= ret; if (p & 1) ret *= b; return ret; }
void EZ(){ 
    int n; cin >> n; 
    vector<int> a ;
    set<int> st; 
    for(int i =0 ;i < n ; i++) {
        int z ; cin >> z; 
        a.pb(z); 
        st.insert(z); 
    }
    // x <=mn  x >= mx
    if(is_sorted(all(a))){ cout << 0 << endl; return; }
    int mx = 0 , mn = 1e9  ; 
    for(int i =0 ;i < n-1  ;i++) {
        if(a[i]<a[i+1])
            mn = min((a[i]+a[i+1])/2 , mn); 
        if(a[i]>a[i+1])
            mx= max((a[i]+a[i+1]+1)/2 , mx); 
        
    } 

    cerr << mx << " " << mn << endl; 
    if(mx > mn) cout << -1 << endl; 
    else{
      
            cout << (mx + mn ) /2 << endl; 
    }
}

int main()
{
    RunIt; 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("Output.txt", "wt", stdout);
#endif
    int tc =1 ;
    cin >> tc;  
    while(tc--){
    	EZ(); 
    }
	return 0;
}
