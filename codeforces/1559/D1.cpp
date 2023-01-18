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
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }


class unionfind {
private  :
    int size;
    int component;
    int *sz;
    int *parent;
public :
    unionfind(int _size) : size(_size), component(_size) {
        sz = new int[_size];
        parent = new int[_size];
        for (int i = 0; i < _size; i++) {
            sz[i] = 1;
            parent[i] = i;
        }
    }

    int Find(int a) {
        if (parent[a] == a) return a;
        int root = a;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (a != root) {
            int temp = parent[a];
            parent[a] = root;
            a = temp;
        }
        return root; // another way of doing that recursively ---> return parent[a] = Find(parent[a]); [can cause memory overhead];
    }

    int componentSize(int p) { return sz[Find(p)]; }

    bool connected(int a, int p) { return (Find(a) == Find(p)); }

    int getcomponent() { return component; }

    void unify(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
        if (root_a == root_b) return;
        if (sz[root_a] < sz[root_b]) swap(root_a, root_b);
        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
        component--;
    }

    ~unionfind() {
        delete[] sz;
        delete[] parent;
    }
};

void EZ() {
    int n , m1, m2 ;
    cin >> n >> m1 >> m2 ;
    unionfind graph1(n) ,graph2(n);

    for(int i =0 ; i < (m1) ; i++) {
        int a, b ;
        cin >> a>> b;
        graph1.unify( a-1 , b-1 ) ;
    }
    for(int i =0 ; i < m2 ; i++) {int a, b ; cin >> a>> b;  graph2.unify(a-1, b-1); }
    vector<pair<int ,int >> ans;
    for(int i =0 ;i <n ;i++ )
        for(int j =0 ; j <n ; j++) {
            if(!graph1.connected(i,j) && ! graph2.connected(i,j)){
                graph1.unify(i,j);
                graph2.unify(i,j);
                ans.pb({i+1,j+1});
            }
        }

    cout << ans.size()  << endl;
    for(auto i : ans ) cout << i.f << " " << i.s << endl;
}


int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
    int tc =1 ; // cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}


