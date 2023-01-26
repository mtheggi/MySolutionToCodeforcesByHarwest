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
int parent[N]; 
int sz[N]; 
int n; 
void init(){
	for(int i =1 ; i<= n ; i++){sz[i] = 1;  parent[i] =i ; }
}
int find(int a ) {
	if(parent[a] == a ) return a;  
	else return parent[a] = find(parent[a]); 
}
void con(int a , int b ) {
    int roota = find(a) , rootb = find(b) ;
    if(roota == rootb) return;
    if(sz[roota] >= sz[rootb]) {
        parent[rootb] = roota ;
        sz[roota]+=sz[rootb] ;
    }else {
        parent[roota] = rootb;
        sz[rootb]+=sz[roota];
    }
}

void EZ(){
	cin >> n ; 
	init();
	vector<pair<int ,int >> g ; 
	for(int i =0 ;i < n-1  ;i++){
		int a, b ; cin >>a >> b ; 
		if(find(a) == find(b)){
			g.pb({a,b});
		}else{
			con(a , b );
		}
	}
	vector<pair<int ,int >> g2; 
	int root = find(1); 
	for(int i =2 ; i<=n ;i++){
		if(find(i) != find(1)) {
			g2.pb({1 , i }); 
			con(1 , i ); 
		}
	}

	cout << g.size() << endl; 
	
	for(int i =0 ; i < g.size() ; i++) {
		cout << g[i].f << " " << g[i].s << " " << g2[i].f << " " << g2[i].s << endl; 
	}

}

#define ll long long
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
    //cin >> tc;  
    while(tc--){
    	EZ(); 
    }
	return 0;
}
