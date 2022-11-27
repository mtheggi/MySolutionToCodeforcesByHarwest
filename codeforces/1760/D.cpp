// Just Keep it up, long way to go.
#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long double
#define el endl
#define re return
#define YES cout << "Yes\n"
#define NO cout << "No\n"
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
const int N = 2e5 +  5  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int n , m  ,zz ;
int dx[8] ={0 ,0 , 1, -1 , 1, -1 , 1 , -1  };
int dy[8] ={1,-1, 0 , 0, 1 , -1 , -1 , 1 };
void bfs(int sn  ){
}
void EZ() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(i == 0 || x != a.back())
        {
            a.push_back(x);
        }
    }
    int v= 0;
    for(int i = 0; i < a.size(); i++)
        if((i == 0 || a[i-1] > a[i]) && (i == a.size()-1 || a[i] < a[i+1])) v++;
    if(v == 1)YES ;
    else NO;
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


