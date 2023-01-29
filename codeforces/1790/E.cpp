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

void setbit(int &a , int i ) {
    a= (a|(1<<i));  
}
bool checkbit(int & a , int i ) {
    return (a&(1<<i)); 
}
void EZ(){
    int n; cin >>  n; 
    int sum = 2*n ; 
    int carry =0 ;
    bool setcarr =0 ;
    int ans1 =0 , ans2=0;

    for(int i = 31 ; i>=0 ;i--){
        bool c2  =checkbit(sum , i ) , c1 = checkbit(n, i );  
        if(!c1 && !c2){
            if(checkbit(carry ,i )) {
                setbit(ans1 , i) ; 
                setbit(ans2 ,i ) ; 
            }
        }else if (c1 && c2 ){
            setbit(ans1, i ) ; 
            if(checkbit(carry ,i )){
                if(i ==0 ) { cout << -1 <<  endl; return; }
                setbit(carry , i-1 ); 
            }
        }else if(!c1 && c2 ){
            if(checkbit(carry , i )) {
                setbit(ans1, i ); 
                setbit(ans2, i); 
            }
            if(i == 0 ) {cout << -1 << endl; return; }
            setbit(carry,i-1); 
        }else{
            if(i == 0 ) {cout << -1 << endl; return;  }
            setbit(carry , i-1) ; 
            setbit(ans1, i ) ; 
        }
    }
    if(ans1^ans2 == n && ans1 + ans2 == sum )
        cout << ans1 << " "  << ans2 << endl; 
    else cout <<-1 << endl;
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
 

    cin >> tc;  
    while(tc--){
    	EZ(); 
    }
	return 0;
}
