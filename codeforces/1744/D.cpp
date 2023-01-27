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
const int offset = 150000;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int n ,m , k ;
int cnt2( int a) {
    int c =0 ;
    while(a%2 ==0 && a>0  ) {
        c++;
        a/=2;
    }
    return c;
}
void EZ() {

    cin >> n ;
    vector<int> v(n +1 ) ;
    vector<bool> vis(n+1 ,0);
    int cnthaving =0 , cntneeded =0;
    vector<int> ind ;
    for(int i =1 ; i<= n ;i++){
        cin >> v[i];
        cnthaving+=cnt2(v[i]);
        ind.pb(cnt2(i));
    }
    cerr<<(cnthaving) << endl;
    if(cnthaving>= n ) { cout << 0 << endl; return; }
    debugv(ind);
    sort(all(ind));
    int ans =0 ;
    for(int i = n-1 ;i >=0 ; i-- ){
        if(ind[i] >0 ){
            cntneeded+=ind[i];
            ans++;
            if((cntneeded + cnthaving )>=n ) {cout << ans << el; return; }
        }
    }
    cout << -1 << endl;
    /*
    while(indx*2 <=n ){
        indx*=2;
    }
    while(indx>=2 ){
        cntneeded+=cnt2(indx);
        vis[indx] = 1;
        indx/=2;
        ans++;
        if((cntneeded + cnthaving) >= n ) {cout << ans << endl ; return; }
    }
    for(int i= n ;i>=1 ;i-- ){
        if(!vis[i]){
            cntneeded+=cnt2(i);
            ans++;
            if((cntneeded + cnthaving) >= n ) {cout << ans << endl ; return; }
        }
    }

    if((cntneeded + cnthaving) < n ) {  cout << -1 << endl; return ; }
    cout << ans << endl;
*/
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
    while(tc-- ){
        EZ();
    }

    ShowTime
    return 0 ;
}


