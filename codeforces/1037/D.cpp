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
bool vis[N];
int order[N]; // fekra gamda fa45
bool compare(int a,  int b) {
    return order[a]<order[b];
}
vector<int> adj[N];
vector<int> ans;
void bfs(int sn  ){
    queue<int> q;
    q.push(sn) ;
    vis[sn] =1 ;
    while(q.size()) {
        int node = q.front();
        q.pop() ;
        for(auto i : adj[node]){
            if(!vis[i]){
                vis[i]= 1;
                q.push(i);
                ans.pb(i);
            }
        }
    }
};
void EZ() {
    cin >>  n;
    vector<int> sol ;
    for(int i =1 ; i< n ; i++) {
        int u ,v ; cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(int i =0 ; i< n ;i++) {
        int u;
        cin >> u;
        sol.pb(u);
        order[u] =i ;
    }
    for(int i = 1 ; i <=n ; i++) {
        sort(all(adj[i]), compare);
    }
    ans.pb(1);
    bfs(1);
    debugv(ans);
    debugv(sol);
    if(ans == sol ) YES ;
    else NO ;
}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc =1 ;
//     cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


