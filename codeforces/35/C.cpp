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
const int N = 2000 +10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int cost[N][N] ;
int n , m ,k , x ,y;
int dx[4] = {0 , 0 , 1 , -1 };
int dy[4] = {1 , -1 , 0 , 0 };
bool inmatrix(int x ,int y ) {
    return(x>0 && x<= n && y >0 &&  y<=m );
}
void EZ(){
    cin >> n >>  m;
    queue<pair<int , int >> q ;
    cin >> k;
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=m; j++) {
            cost[i][j] = 1e9;
        }
    }
    while(k--){
        cin >> x >> y;
        q.push({x, y});
        cost[x][y] =0  ;
    }
    while(q.size()){
        x= q.front().first ;  y = q.front().second ;
        q.pop();
        int cur_cost = cost[x][y];
        int newcost = cur_cost + 1;
        for(int i =0   ; i < 4;  i++) {
                int nx = x + dx[i]  , ny = y + dy[i];
                if(cost[nx][ny] > newcost  && inmatrix(nx,ny)) {
                    cost[nx][ny] = newcost;
                    q.push({nx ,ny});
                }
        }
    }
    int ansx , ansy , mx = -1  ;
    for(int i =1; i <=n ;i++){
        for(int j =1 ; j<=m ;j++){
            if(cost[i][j] > mx){
                ansx = i  ; ansy  =j ;
                mx = cost[i][j];
            }
        }

    }
    cout << ansx << " " << ansy << endl;
}


int main() {
    RunIt;
//#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("Error","w",stderr);
//#endif

    int tc =1 ;
 //    cin >> tc;
    for(int i =1 ; i <=tc ; i++) EZ();


    ShowTime
    return 0 ;
}


