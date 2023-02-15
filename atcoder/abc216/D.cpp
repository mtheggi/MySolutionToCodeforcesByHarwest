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
const int N = 1000 ,  M = 2e5 + 10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
void EZ() {
    int n , m ;
    cin >> n >> m;
    vector<queue<int>> cyl(m+1 );
    vector<vector<int>> colorsIndices(n+1) ;
    for(int i =1 ;i <=m ; i++ ) {
        int k; cin >> k ;
        while(k--){
            int a; cin >> a;
            cyl[i].push(a);
        }
        colorsIndices[cyl[i].front()].push_back(i);
    }
    queue<int> q;
    for(int i =1 ;i <=n ; i++) {
        if(colorsIndices[i].size() == 2 ) q.push(i);
    }
    while(!q.empty()){
        int front = q.front() ; q.pop();
        for(int i =0 ; i< colorsIndices[front].size() ; i++ ){
            int l =colorsIndices[front][i];
            cyl[l].pop();
            if(cyl[l].size()) {
                int color = cyl[l].front();
                colorsIndices[color].push_back(l);
                if(colorsIndices[color].size() == 2) q.push(color);
            }
        }

    }
    for(auto i : cyl) if(i.size()) {NO;re;}
    YES;
}





int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc =1 ;
//    cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}

