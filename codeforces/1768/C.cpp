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
    const ll MOD = LLONG_MAX;
    const double EPS = 1e-9;
    const int N = 5e5 +10  ;
    const ll inf = 1e18 ;
    // used Funcions
    ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
    ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
    ll fastpow( ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, (p >> 1)); ret =(ret * ret)%MOD; if (p & 1) {ret *= b; ret = ret %MOD ;} return ret; }
    void EZ(int tc) {
        int n;
        cin >> n ;
        cerr << n << el;
        set<int> pst , dst ;
        map<int ,int > freq;
        vector<int> a(n) , p(n, -1 ) ,d(n ,-1);
        for(int i =0 ;i  < n  ; i++) {
            cin >> a[i];
            freq[a[i]]++;
            pst.insert(-i-1);  dst.insert(-i-1);
        }
        for(int i =0 ; i < n ; i++) if(freq[a[i]] > 2 ) {NO; re; }
        if(freq[1] >1 ) {NO ;re; }
        for(int i =0 ; i < n ; i++) {
            if(pst.find(-a[i]) != pst.end()){
                p[i] = a[i];
                pst.erase(-a[i]);
            }
            else {
                if(dst.find(-a[i]) != dst.end()) {d[i] = a[i];dst.erase(-a[i]); }
                else {NO ;re;}
            }
        }
//        debugv(d);
  //      debugv(p);
        for(int i =0 ; i< n ; i++) {
            if(p[i] == -1 ){
                auto it = pst.lower_bound(-d[i]);
                if(it == pst.end()){NO; re; }
                else { p[i] = -(*it) ; pst.erase(it) ; }
            }
            if(d[i] == -1 ){
                int val = -1 * p[i];
                auto it = dst.lower_bound(val);
                if(it == dst.end()){NO; re; }
                else { d[i] = -(*it) ; dst.erase(it) ; }
            }
        }
        YES;
        for(auto i : p ) cout << i << " " ;
        cout << el;
        for(auto i : d ) cout << i << " " ;
        cout  << el;
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
        for(int i =1 ; i<=tc ; i++)
            EZ(i);

        ShowTime
        return 0  ;
    }