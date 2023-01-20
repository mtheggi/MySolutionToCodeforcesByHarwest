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
const int N = 6e5 +10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }

bool prime[N];
int spf[N]; // smallest Prime Factor
void sieve()
{ // O(n * (log(log(n)))
    memset(prime, true, sizeof prime);
    for (int i = 1; i < N; i++)
        spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {

        for (int j = i + i; j < N; j += i)
        {
            prime[j] = false;
            spf[j] = min(spf[j], i);
        }
    }
}
int const offset = 3e5;
vector<int> SieveFact(int n)
{ // O(log(n))
    set<int> v;
    while (n > 1)
    {
        v.insert(spf[n] );
        n /= spf[n];
    }
    vector<int> ans;
    for(auto i : v) ans.pb(i);
    return ans;
}
vector<vector<int>> graph(N);
int parent[N];
int n;
bool vis[N];
vector<int> bfs(int src ,int dest ) {
    queue<int> q ;
    q.push(src);
    vector<int> ans;
    
    parent[src] = -1 ;
    vis[src] =1 ;
    bool found = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i =0 ;i < graph[front].size() ; i++){
            if(! vis[graph[front][i]] ){
                vis[graph[front][i]] = 1 ;
                q.push(graph[front][i]);
                parent[graph[front][i]] = front;
                if( graph[front][i] == dest) {
                    found =1 ;
                    break;
                }

            }
        }
        if(found) break;
    }
    if(!found )
        ans.clear();
    else {
        int searchpath = dest ;
        while(searchpath != -1 ) {
            if(searchpath <=n ){
                ans.pb(searchpath)  ;
            }
            searchpath = parent[searchpath];
        }
        reverse(all(ans));
    }

    return ans;
}
/*
    1 : 2 + 10
    2 : 2+10 , 7+ 10
    3 : 3+10 ;
    4 : 2+10 , 3+10
    5 : 2+ 10
    6 : 3+ 10 , 5+ 10
    7 : 11 + 10
    2+10 : 1 ,2 ,4 ,5
    7+10 : 2
    3+10 : 3, 4 , 6
    5+10 : 6
    11 + 10 : 7






 */
void EZ() {
    sieve() ;
    memset(parent , -1 , sizeof parent );
    int src, dest ;
    cin >> n ;
    vector<int> legs(n);

    for(int i=0 ;i < n ;i++) {cin >> legs [i] ; }
    cin >> src >> dest ;
    if(src == dest ) {cout << 1 << endl <<   src << endl; re; }
    for(int i =0 ; i< n ;i++) {
        vector<int> primes = SieveFact(legs[i]);
        for(int j =0 ;j < primes.size() ; j++) {
            graph[i + 1].pb(primes[j] + offset);
            graph[primes[j] + offset].pb(i + 1);
        }
    }
    vector<int> ans = bfs(src  ,dest );
    if(ans.size() == 0){ cout << -1 << endl; return; }
    cout << ans.size() << endl;
    for(auto i : ans ) cout << i << " ";

}

int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ;  //cin >> tc;
    while(tc--){
        EZ();
    }
    ShowTime
    return 0 ;
}


